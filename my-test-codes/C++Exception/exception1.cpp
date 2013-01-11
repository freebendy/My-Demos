#include "MyException.h"

// 这是全局变量的异常对象 
//MyException ex_global_obj("ex_global_obj"); 
int main() 
{ 
	try 
	{ 
		{ 
			// 构造一个异常对象，这是局部变量 
			MyException ex_obj1("ex_obj1"); 
			throw ex_obj1; 
			// 这种也是临时变量 
			// 这种方式是最常见抛出异常的方式 
			//throw MyException("ex_obj2");  //g++在这里之构造一次异常，vc是2次
			// 这种异常对象原来是在堆中构造的 
			// 但这里也会复制一份新的异常对象 
			// 注意：这里有资源泄漏呦！ 
			//throw *(new MyException("ex_obj2")); 
			// 全局变量 
			// 同样这里也会复制一份新的异常对象 
			//throw ex_global_obj; 
		} 
	} 
	catch(...) 
	{ 
		cout<<"catch unknow exception"<<endl; 
	}
} 
