#include<iostream>
using namespace std;

// max.h
template <class Type>
Type Max(Type t1,Type t2)
{
	return (t1>t2 ? t1 : t2);
}

// const char*显式特化：覆盖了来自通用模板定义的实例

typedef const char *PCC;
template<> 
PCC Max< PCC >( PCC s1, PCC s2 ) //特化
{
		 return (strcmp(s1,s2)>0 ? s1 :s2);
}

// user.c
int main()
{
	// 调用实例：int  Max< int >( int, int );
	int  i = Max( 10, 5 );
	// 调用显式特化：const char* Max< const char* >( const char*, const char* );
	const char *p = Max( "hello", "world" ); 
	cout<<"i: "<<i<<" "<<"p: "<<p<<endl;

	return 0;
}
