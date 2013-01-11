#include <stdio.h>

typedef enum State {
    OUT = 0, 
    IN = 1
} State;

int main(int argc, char const *argv[])
{
    int c, nl, nw, nc;
    State state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
