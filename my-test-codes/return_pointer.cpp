#include <iostream>
using namespace std ;

char* GetString2(void)
{
	char *p = "hello world" ;
	//char p[] = "hello world" ;
	return p ;
}

int main()
{
	char *str = NULL ;
	str = GetString2() ;
	//char *test="111";
	//cout<<test<<endl;
	cout << str << endl ;
	return 0 ;
}

/*
**д����������������ԭ��
**����char *p �� ��hello world ���ĳ� char p[] = "hello world"
**����ṹ��ԭ��
**
**�����Ŀ�ǳ��򵥡�
**���ǣ�Ҫ������Ĵ�����ȷ���Ǻ����ס�
**1.����ִ�нṹ��hello world.
**   ��char *p = "hello world"������ʽȥ��ʼ��������p ָ��̬�洢�������Կ���ִ�С�
**
**2.����ջ�ڱ��������ԣ��޷�������ʾ��
*/

