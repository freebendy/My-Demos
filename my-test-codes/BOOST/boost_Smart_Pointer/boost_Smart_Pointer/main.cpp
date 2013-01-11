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

	//boost::scoped_ptr<CTest> pTest1 = pTest ; //����scoped_ptr������Ȩ����ת��

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
scoped_ptr : û�С���������Ȩ�����ǡ�����Ȩת�á�����,�������ڲ�Ӧ�����Ƶ�ָ��ʱ������shared_ptr ��std:auto_ptr Ҫ����ȫ

scoped_array����ģ������scoped_ptr ���ƣ�������������������ǵ�������

shared_ptr:����C++��׼��ġ��ɸ��ƹ��족��CopyConstructible���͡��ɸ�ֵ����Assignable��Ҫ�����Կɱ����ڱ�
	׼�Ŀ������С����������ṩ�˱Ƚϲ����������Կ����׼��Ĺ�������һ������shared_ptr �������ڴ洢ָ
	��̬����������ָ�룬���������Ӧ��ʹ��shared_array����ģ���ʵ�ֲ��������ü��������������޷�
	��ȷ����ѭ�����õ����������ʹ��weak_ptr ��������ѭ������shared_ptr �����ڶ��̻߳�����ʹ��.

weak_ptr����ģ����洢������shared_ptr ����Ķ��󡱵ġ������á���Ҫ����weak_ptr ��ָ��Ķ�
	�󣬿���ʹ��shared_ptr ��������make_shared ��������weak_ptr ת��Ϊshared_ptr��ָ�򱻹������
	�����һ��shared_ptr ������ʱ��ɾ���ö��󣬼�ʹ����weak_ptr ָ����Ҳ����ˡ���ԭʼָ�벻ͬ���ǣ�
	��ʱ���һ��shared_ptr �����Ƿ���weak_ptr ָ��ö�������еĻ��ͽ���Щweak_ptr ��Ϊ�ա�����
	�Ͳ��ᷢ��ʹ��ԭʼָ��ʱ���ܳ��ֵġ�����ָ�롱��dangling pointer��������Ӷ���ø��ߵİ�ȫˮƽ��
	weak_ptr ����C++��׼��ġ��ɸ��ƹ��족��CopyConstructible���͡��ɸ�ֵ����Assignable��Ҫ��
	���Կɱ����ڱ�׼�Ŀ������С����������ṩ�˱Ƚϲ����������Կ����׼��Ĺ�������һ������

************************************************************************/

