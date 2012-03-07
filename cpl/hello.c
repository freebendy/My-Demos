#include <stdio.h>
//#include "ss.h"

void test(int a[])
{
    //The length of the pointer -- 8 in 64bit system
    printf("sizeof a is :%ld\n", sizeof(a));
}

int main(int argc, char *argv[])
{
    char buf[1024];
    //The length of the memory by byte.
    printf("sizeof buf is :%ld\n", sizeof(buf));
    //The length of the char by byte.
    printf("sizeof buf[0] is :%ld\n", sizeof(buf[0]));
    int i[10];
    printf("sizeof i is :%ld\n", sizeof(i));
    printf("sizeof i[0] is :%ld\n", sizeof(i[0]));
    
    test(i);

    int t;
    printf("t = %d\n", t);

    //pp();

    return 0;
}

