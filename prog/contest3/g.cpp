#include <stdio.h>

#define ll long long int
#define divisor 1000000007

ll fast_power(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fast_power(a * a % divisor, n / 2) % divisor;
    else
        return a * fast_power(a, n - 1) % divisor;
}

ll res_func(ll a, ll b, ll c, ll d)
{
    ll f = a * fast_power(b, divisor - 2) % divisor;
    ll l = c * fast_power(d,divisor-2) % divisor;
    if (f < 0) f += divisor;
    if (l < 0) l += divisor;
    ll res = (f + l) % divisor;
    return res;
}

int main()
{
    ll a = 0, b = 0, c = 0, d = 0;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    printf("%lld\n", res_func(a, b, c, d));
    return 0;
}