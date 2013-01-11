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
**写出输出结果，并分析原因。
**当把char *p ＝ “hello world ”改成 char p[] = "hello world"
**输出结构和原因。
**
**这个题目非常简单。
**但是，要很清楚的答明白确不是很容易。
**1.程序执行结构是hello world.
**   用char *p = "hello world"这种形式去初始化变量。p 指向静态存储区。所以可以执行。
**
**2.是在栈内变量。所以，无法正常显示。
*/

