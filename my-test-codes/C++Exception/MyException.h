#include <iostream>
#include <string>
using namespace std;

class MyException
{
	public:
		MyException(string name="none") : m_name(name)
		{
			cout<<"构造一个MyException对象，名称为："<<m_name<<endl;
		}
		MyException(const MyException &old_e)
		{
			m_name = old_e.m_name ;
			cout<<"拷贝一个MyException对象，名称为："<<m_name<<endl;
		}
		MyException& operator =(const MyException &old_e)
		{
			m_name = old_e.m_name ;
			cout<<"赋值拷贝一个MyException对象，名称为："<<m_name<<endl;
		}
		virtual ~MyException()
		{
			cout<<"销毁一个MyException对象，名称为："<<m_name<<endl;
		}
		string GetName()
		{
			return m_name ;
		}
		protected:
			string m_name ;
};
