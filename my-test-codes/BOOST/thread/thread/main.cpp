#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/tss.hpp>
#include <boost/thread/once.hpp>
#include <iostream>

const int BUF_SIZE = 10 ;
const int ITERS = 100 ;

boost::mutex io_mutex ;
boost::thread_specific_ptr<int> ptr ;

int i = 0 ;
boost::once_flag flag = BOOST_ONCE_INIT ;

void init()
{
    ++i ;
}

void thread()
{
    boost::call_once(&init,flag) ;
}

struct count
{
    count(int id) : id(id) {}

    void operator() ()
    {
        for (int i = 0; i < 10; ++ i)
        {
            boost::mutex::scoped_lock lock(io_mutex) ;
            std::cout<<id<<": "<<i<<std::endl ;
        }
    }

    int id ;
};

struct count1
{
    count1(int id) : id(id) {}

    void operator() ()
    {
        if(ptr.get() == 0)
            ptr.reset(new int(0)) ;

        for (int i = 0; i < 10; ++i)
        {
            (*ptr) ++ ;
            boost::mutex::scoped_lock lock(io_mutex) ;
            std::cout<<id<<": "<<*ptr<<std::endl ;
        }
    }

    int id ;
};

class buffer
{
public:
    typedef boost::mutex::scoped_lock scoped_lock ;

    buffer() : p(0), c(0), full(0)
    {
    }

    void put(int m)
    {
        scoped_lock lock(mutex);
        if (full == BUF_SIZE)
        {
            {
                scoped_lock lock(io_mutex);
                std::cout<<"Buffer is full. Waiting..."<<std::endl ;
            }
            while (full == BUF_SIZE)
            {
                cond.wait(lock) ;
            }
        }
        buf[p] = m ;
        p = (p+1) % BUF_SIZE ;
        ++full ;
        cond.notify_one();
    }

    int get()
    {
        scoped_lock lk(mutex) ;
        if(full == 0)
        {
            {
                scoped_lock lock(io_mutex) ;
                std::cout<<"Buffer is empty. Waiting..."<<std::endl ;
            }
            while (full == 0)
                cond.wait(lk) ;
        }
        int i = buf[c] ;
        c = (c+1) % BUF_SIZE ;
        --full ;
        cond.notify_one() ;
        return i ;
    }
private:
    boost::mutex mutex ;
    boost::condition cond ;
    unsigned int p,c,full ;
    int buf[BUF_SIZE] ;
};

buffer buf ;

void writer()
{
    for (int n = 0; n < ITERS; ++n)
    {
        {
            boost::mutex::scoped_lock lock(io_mutex) ;
            std::cout<<"sending: "<<n<<std::endl ;
        }
        buf.put(n) ;
    }
}

void reader()
{
    for (int x = 0; x < ITERS; ++x)
    {
        int n= buf.get() ;
        {
            boost::mutex::scoped_lock lock(io_mutex) ;
            std::cout<<"received: "<<n<<std::endl ;
        }
    }
}

int main()
{
    //boost::thread thrd1(count(1)) ;
    //boost::thread thrd2(count(2)) ;
    //boost::thread thrd1(&reader) ;
    //boost::thread thrd2(&writer) ;
    //boost::thread thrd1(count1(1)) ;
    //boost::thread thrd2(count1(2)) ;
    boost::thread thrd1(&thread) ;
    boost::thread thrd2(&thread) ;
    thrd1.join() ;
    thrd2.join() ;
    std::cout<<i<<std::endl ;
    return 0 ;
};