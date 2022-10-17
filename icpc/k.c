#include <stdio.h>

typedef unsigned long long ull;

ull k(ull n)
{
    ull x = 5, s = 0;

    while (x <= n)
    {
        s += (n / x);
        x *= 5;
    }
    return s;
}

ull g(ull n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 3;
    }
    else if (n == 4 || n == 5 || n == 6 || n == 8)
    {
        return 4;
    }
    else if (n == 7)
    {
        return 8;
    }
    else if (n == 9)
    {
        return 6;
    }
}

