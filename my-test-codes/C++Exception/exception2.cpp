#include "MyException.h"

using namespace std ;

int main()
{
	try
	{
		{
			MyException ex_obj1("ex_obj1") ;
			throw ex_obj1 ;
		}
	}
	catch (MyException e)
	{
		cout<<"����һ��MyException���͵��쳣������Ϊ��"<<e.GetName()<<endl ;
	}
	return 0 ;
}
