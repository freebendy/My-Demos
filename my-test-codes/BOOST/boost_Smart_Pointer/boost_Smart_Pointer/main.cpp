#include "boost/scoped_ptr.hpp"
#include "boost/scoped_array.hpp"
#include <iostream>
#include "boost/shared_ptr.hpp"
#include "boost/shared_array.hpp"
#include "boost/weak_ptr.hpp"

#include <vector>
#include <algorithm>
#include <cassert>

class CTest ;

typedef boost::shared_ptr<CTest> TestPtr ;


class CTest
{
public:
	CTest() : m_id(0) {}
	CTest(int id) : m_id(id) {}
	~CTest() { std::cout << "id: " << m_id << " -Destructor is being  called!\n" ; }
	
	void SetId(int id) { m_id = id ; }
	int GetId() const { return m_id ; } 
	
	void DoSomething() { std::cout << "id: " << m_id << "- Doing Something!\n" ;}

private:
	int m_id ;
};

void PT(const TestPtr &t)
{
	std::cout << "id:  " << t->GetId() << "\t\t" << "use count: " << t.use_count() << '\n' ;
}

int main()
{
	std::cout<< "\nBegin scoped_ptr !!\n" << '\n' ;
	boost::scoped_ptr<CTest> pTest(new CTest) ;
	pTest->DoSomething() ;

	std::cout<< "\nBegin scoped_array !!\n" << '\n' ;
	boost::scoped_array<CTest> pTestArr(new CTest[2]) ;
	pTestArr[0].SetId(2) ;
	pTestArr[1].SetId(3) ;
	pTestArr[0].DoSomething() ;
	pTestArr[1].DoSomething() ;

	std::cout<< "\nBegin shared_ptr !!\n" << '\n' ;
	std::vector<TestPtr> TestVector ;
	TestPtr pTest0(new CTest(4)) ;
	pTest0->DoSomething() ;
	TestVector.push_back(pTest0) ;

	TestPtr pTest1(new CTest(5)) ;
	pTest1->DoSomething() ;
	TestVector.push_back(pTest1) ;
	
	TestPtr pTest2(new CTest(6)) ;
	pTest2->DoSomething() ;
	TestVector.push_back(pTest2) ;

	std::for_each(TestVector.begin(),TestVector.end(),PT) ;
	std::cout << '\n' ;

	pTest0.reset() ;
	pTest1.reset() ;
	pTest2.reset() ;

	std::for_each(TestVector.begin(),TestVector.end(),PT) ;
	std::cout << '\n' ;

	TestVector.clear() ;
	std::cout	<< '\n' ;

	std::cout << "exiting...\n" ;

	std::cout<< "\nBegin shared_array !!\n" << '\n' ;
	boost::shared_array<CTest> pTestArr1(new CTest[2]) ;
	pTestArr1[0].SetId(7) ;
	pTestArr1[1].SetId(8) ;

	std::cout << "use count: " << pTestArr1.use_count() << "\n\n" ;
	boost::shared_array<CTest> pTestArr2(pTestArr1) ;
	std::cout << "use count: " << pTestArr1.use_count() << "\n\n" ;
	pTestArr1.reset() ;
	
	pTestArr2[0].DoSomething() ;
	pTestArr2[1].DoSomething() ;
	std::cout << '\n' ;

	std::cout << "use count: " << pTestArr1.use_count() << "\n\n" ;

	std::cout<< "\nBegin weak_ptr !!\n" << '\n' ;
	boost::shared_ptr<CTest> pTest3(new CTest(9)) ;
	boost::weak_ptr<CTest> pTest4(pTest3) ;

	if(boost::shared_ptr<CTest> pTest5 = boost::make_shared(pTest4))
		pTest5->DoSomething() ;

	pTest3.reset() ;

	assert(pTest3.get() == NULL) ;

	//boost::scoped_ptr<CTest> pTest1 = pTest ; //错误scoped_ptr的所有权不能转让

    boost::shared_ptr<int> shared1(new int(10)) ;
    boost::shared_ptr<int> shared2 = shared1 ;
    std::cout<<*shared1<<std::endl ;
    std::cout<<*shared2<<std::endl ;
    std::cout<<shared1<<std::endl ;
    std::cout<<shared2<<std::endl ;

    *shared1 = 11 ;

    std::cout<<*shared1<<std::endl ;
    std::cout<<*shared2<<std::endl ;
    std::cout<<shared1<<std::endl ;
    std::cout<<shared2<<std::endl ;

	return 0 ;
}

/************************************************************************
scoped_ptr : 没有“共享所有权”或是“所有权转让”语义,，在用于不应被复制的指针时，它比shared_ptr 或std:auto_ptr 要更安全

scoped_array：该模板类与scoped_ptr 类似，但意在用于数组而不是单个对象

shared_ptr:符合C++标准库的“可复制构造”（CopyConstructible）和“可赋值”（Assignable）要求，所以可被用于标
	准的库容器中。另外它还提供了比较操作符，所以可与标准库的关联容器一起工作。shared_ptr 不能用于存储指
	向动态分配的数组的指针，这样的情况应该使用shared_array。该模板的实现采用了引用计数技术，所以无法
	正确处理循环引用的情况。可以使用weak_ptr 来“打破循环”。shared_ptr 还可在多线程环境中使用.

weak_ptr：该模板类存储“已由shared_ptr 管理的对象”的“弱引用”。要访问weak_ptr 所指向的对
	象，可以使用shared_ptr 构造器或make_shared 函数来将weak_ptr 转换为shared_ptr。指向被管理对象
	的最后一个shared_ptr 被销毁时将删除该对象，即使仍有weak_ptr 指向它也是如此。与原始指针不同的是，
	届时最后一个shared_ptr 会检查是否有weak_ptr 指向该对象，如果有的话就将这些weak_ptr 置为空。这样
	就不会发生使用原始指针时可能出现的“悬吊指针”（dangling pointer）情况，从而获得更高的安全水平。
	weak_ptr 符合C++标准库的“可复制构造”（CopyConstructible）和“可赋值”（Assignable）要求，
	所以可被用于标准的库容器中。另外它还提供了比较操作符，所以可与标准库的关联容器一起工作。

************************************************************************/

