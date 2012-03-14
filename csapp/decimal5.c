int decimal5(int *x)
{
    int i;
    int val = 0;

    for (i = 0; i < 5; i++)
        val = (10 * val) + x[i];

    return val;
}

