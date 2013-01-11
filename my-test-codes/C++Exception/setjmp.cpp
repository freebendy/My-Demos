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
//�Ǹ����jmp_buf �ĺ������ڵ���longjmp()֮ǰ���ء����򣬴洢��jmp_buf �е���
//���ľ���������(��˼��main�����ڵ���longjmpǰ����)
//�����setjmp()�����ֻ�ǵ�������λ�õ�һ���Ǿֲ���ת
