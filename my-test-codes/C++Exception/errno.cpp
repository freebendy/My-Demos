#include <errno.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
	double x, y, result;
	x = 213.12;
	y = 24.21;
	// ... somehow set 'x' and 'y' ... 
	errno = 0;
	result = pow(x, y);
	printf("%d\n",errno) ;
	if (errno == EDOM)
		printf("domain error on x/y pair\n");
	else if (errno == ERANGE)
		printf("range error on result\n");
	else
		printf("x to the y = %d\n", (int) result);
	return 0;
}

/*
//注意：errno 不一定要绑在一个对象上：
int *_errno_function()
{
	static int real_errno = 0;
	return &real_errno;
}
#define errno (*_errno_function())
int main(void)
{
	errno = 0;
	// ... 
	if (errno == EDOM)
		;
	// ... 
}
*/
