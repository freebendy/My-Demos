#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test
{
	char *p_ch ;
	int ix ;
};

int main(int argc, char *argv[])
{
	struct test *p_test ;
	p_test = (struct test*)malloc(sizeof(struct test)) ;
	p_test->p_ch = (char*)malloc(20) ;
	char *p_ch = "hello!" ;
	strcpy(p_test->p_ch,p_ch) ;
	p_ch = p_test->p_ch ;
	printf("p_test->p_ch: \t%s\n",p_test->p_ch) ;
	free(p_test->p_ch) ; //×¢ÊÍ´ËĞĞ£¬p_chÈÔÎª"hello!"
	free(p_test) ;
	printf("after free(p_test),p_ch: \t%s\n",p_ch) ;
	return 0;
}
