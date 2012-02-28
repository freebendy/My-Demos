#include <stdio.h>

union u1 {
    char sex;
    int length;
    long l;
};

int main(char **argv, int argc)
{
    printf("char: %ld\n", sizeof(char));
    printf("short: %ld\n", sizeof(short));
    printf("float: %ld\n", sizeof(float));
    printf("double: %ld\n", sizeof(double));
    printf("int: %ld\n", sizeof(int));
    printf("long: %ld\n", sizeof(long));
    printf("void*: %ld\n", sizeof(void *));
    printf("u1: %ld\n", sizeof(union u1));
    return 0;
}

