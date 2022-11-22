#include <stdio.h>

#define l long
#define p 1000000009

l fast_power(l a, l n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fast_power((a * a) % p, n / 2) % p;
    else
        return (a * fast_power(a, n - 1)) % p;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    l a = 0, x = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &a);
        x = fast_power(a, p - 2);
        printf("%ld\n", x);
    }
}