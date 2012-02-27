#include <stdio.h>

struct stu {
    char sex;
    int length;
//    char name[10];
//    long l;
    long l[10];
};

struct stu1 {
    char sex;
    int length;
    long l;
};

int main(char **argv, int argc)
{
    struct stu test;
//    printf("%ld\n", sizeof(test.name));
    printf("char: %ld\n", sizeof(char));
    printf("short: %ld\n", sizeof(short));
    printf("float: %ld\n", sizeof(float));
    printf("double: %ld\n", sizeof(double));
    printf("int: %ld\n", sizeof(int));
    printf("long: %ld\n", sizeof(long));
    printf("void*: %ld\n", sizeof(void *));
    printf("stu: %ld\n", sizeof(struct stu));
    printf("stu1: %ld\n", sizeof(struct stu1));
    return 0;
}

