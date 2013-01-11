#include <setjmp.h>
#include <stdio.h>

jmp_buf j;
void raise_exception(void)
{
	printf("exception raised\n");
	longjmp(j, 1); // jump to exception handler 
	printf("this line should never appear\n");
}
int main(void)
{
	if (setjmp(j) == 0)
	{
		printf("'setjmp' is initializing 'j'\n");
		raise_exception();
		printf("this line should never appear\n");
	}
	else
	{
		printf("'setjmp' was just jumped into\n");
		// this code is the exception handler
	}
	return 0;
}

/* When run yields:
	'setjmp' is initializing 'j'
	exception raised
	'setjmp' was just jumped into
*/
/*
jmp_buf j;
void f(void)
{
	setjmp(j);
}
int main(void)
{
	f();
	longjmp(j, 1); // logic error 
	return 0;
}
*/
//那个填充jmp_buf 的函数不在调用longjmp()之前返回。否则，存储在jmp_buf 中的上
//下文就有问题了(意思是main不能在调用longjmp前返回)
//必须把setjmp()处理成只是到其所在位置的一个非局部跳转
