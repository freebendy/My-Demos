#include "MyException.h"

// ����ȫ�ֱ������쳣���� 
//MyException ex_global_obj("ex_global_obj"); 
int main() 
{ 
	try 
	{ 
		{ 
			// ����һ���쳣�������Ǿֲ����� 
			MyException ex_obj1("ex_obj1"); 
			throw ex_obj1; 
			// ����Ҳ����ʱ���� 
			// ���ַ�ʽ������׳��쳣�ķ�ʽ 
			//throw MyException("ex_obj2");  //g++������֮����һ���쳣��vc��2��
			// �����쳣����ԭ�����ڶ��й���� 
			// ������Ҳ�Ḵ��һ���µ��쳣���� 
			// ע�⣺��������Դй©�ϣ� 
			//throw *(new MyException("ex_obj2")); 
			// ȫ�ֱ��� 
			// ͬ������Ҳ�Ḵ��һ���µ��쳣���� 
			//throw ex_global_obj; 
		} 
	} 
	catch(...) 
	{ 
		cout<<"catch unknow exception"<<endl; 
	}
} 
