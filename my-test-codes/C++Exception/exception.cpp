#include "MyException.h"

int main() 
{ 
	try 
	{ 
		{ 
			// ����һ���쳣�������Ǿֲ����� 
			MyException ex_obj1("ex_obj1"); 
			// �����׳��쳣���� 
			// ע����ʱVC�������Ḵ��һ���µ��쳣������ʱ���� 
			throw ex_obj1; 
		} 
	} 
	catch(...) 
	{ 
		cout<<"catch unknow exception"<<endl; 
	}
	return 0 ;
} 



