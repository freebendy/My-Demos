#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    long nc;

    nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        printf("/");
        putchar(c);
    }
    printf("%ld\n", nc);
    return 0;
}
