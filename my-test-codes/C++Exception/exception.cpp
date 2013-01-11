#include "MyException.h"

int main() 
{ 
	try 
	{ 
		{ 
			// 构造一个异常对象，这是局部变量 
			MyException ex_obj1("ex_obj1"); 
			// 这里抛出异常对象 
			// 注意这时VC编译器会复制一份新的异常对象，临时变量 
			throw ex_obj1; 
		} 
	} 
	catch(...) 
	{ 
		cout<<"catch unknow exception"<<endl; 
	}
	return 0 ;
} 



