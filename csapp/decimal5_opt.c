int decimal5(int *x)
{
    int val = 0;
    int *xend = x +4;

    do {
        val = (10 * val) + *x;
        x++;
    } while (x <= xend);

    return val;
}

