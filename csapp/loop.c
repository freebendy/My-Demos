#include <stdio.h>

/*
 * 利用环的属性，不借助额外的变量来交换2个变量的值
 */

void inplace_swap(int *x, int *y)
{
    *x = *x ^ *y;
    printf("after step 1:\n*x = %d\n*y = %d\n", *x, *y);
    *y = *x ^ *y;
    printf("after step 2:\n*x = %d\n*y = %d\n", *x, *y);
    *x = *x ^ *y;
    printf("after step 3:\n*x = %d\n*y = %d\n", *x, *y);
}

int main(int argc, char **argv)
{
    int a = 16;
    int b = 18;
    printf("before swap:\na = %d\nb = %d\n", a, b);
    inplace_swap(&a, &b);
    printf("afrer swap:\na = %d\nb = %d\n", a, b);

    return 0;
}
