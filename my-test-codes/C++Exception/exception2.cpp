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
		cout<<"捕获到一个MyException类型的异常，名称为："<<e.GetName()<<endl ;
	}
	return 0 ;
}
