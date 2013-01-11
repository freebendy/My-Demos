#include <iostream>
#include <boost/signals.hpp>

struct Hello
{
    void operator() () const
    {
        std::cout<<"Hello," ;
    }
};

struct World 
{
    void operator() () const
    {
        std::cout<<"World!"<<std::endl ;
    }
};

struct Ben
{
    void operator() () const
    {
        std::cout<<"Ben! " ;
    }
};

int main()
{
    boost::signal<void ()> sig ;
    Hello hello ;
    World world ;
    Ben ben ;
    sig.connect(1,hello) ;
    sig.connect(2,world) ;
    sig.connect(0,ben) ;

    sig() ;

    return 0 ;

}