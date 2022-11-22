#include <stdio.h>

#define ll long long int
#define divisor 1000003

ll fact(ll n)
{
    if (divisor <= n)
        return 0;
    int rest = 1;
    for (ll i = 2; i <= n; i++)
        rest = (rest * i) % divisor;
    return rest;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld", fact(n));
    return 0;
}