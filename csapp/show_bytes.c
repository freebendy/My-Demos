#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(x));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(x));
}

void show_point(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(x));
}

int main(int argc, char **argv)
{
    int ival = 12345;
    float fval = 12345.0;
    int *pval = &ival;
    show_int(ival);
    show_float(ival);
    show_point(pval);

    char *s = "ABCDEF";
    show_bytes(s, strlen(s));

    short x = 12345;
    short mx = -12345;
    show_bytes((byte_pointer) &x, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));


    return 0;
}

