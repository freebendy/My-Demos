#include<iostream>
using namespace std;

// max.h
template <class Type>
Type Max(Type t1,Type t2)
{
	return (t1>t2 ? t1 : t2);
}

// const char*��ʽ�ػ�������������ͨ��ģ�嶨���ʵ��

typedef const char *PCC;
template<> 
PCC Max< PCC >( PCC s1, PCC s2 ) //�ػ�
{
		 return (strcmp(s1,s2)>0 ? s1 :s2);
}

// user.c
int main()
{
	// ����ʵ����int  Max< int >( int, int );
	int  i = Max( 10, 5 );
	// ������ʽ�ػ���const char* Max< const char* >( const char*, const char* );
	const char *p = Max( "hello", "world" ); 
	cout<<"i: "<<i<<" "<<"p: "<<p<<endl;

	return 0;
}
