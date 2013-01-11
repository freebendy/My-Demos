#include <iostream>
#include <string>
using namespace std;

class MyException
{
	public:
		MyException(string name="none") : m_name(name)
		{
			cout<<"����һ��MyException��������Ϊ��"<<m_name<<endl;
		}
		MyException(const MyException &old_e)
		{
			m_name = old_e.m_name ;
			cout<<"����һ��MyException��������Ϊ��"<<m_name<<endl;
		}
		MyException& operator =(const MyException &old_e)
		{
			m_name = old_e.m_name ;
			cout<<"��ֵ����һ��MyException��������Ϊ��"<<m_name<<endl;
		}
		virtual ~MyException()
		{
			cout<<"����һ��MyException��������Ϊ��"<<m_name<<endl;
		}
		string GetName()
		{
			return m_name ;
		}
		protected:
			string m_name ;
};
