#include <stdio.h>
#include <algorithm>

bool is_true(long long max, long long* arr, long long k, long long n)
{
    long long a = 0;
    for (long long i = 0; i < n; i++)
    {
        a += arr[i] / max;
        if (a >= k)
            return true;
    }
    return false;
}

long long solve(long long* arr, long long k, long long n, long long r)
{
    long long l = 0;
    long long mid = 0;

    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (is_true(mid, arr, k, n))
            l = mid;
        r = mid;
    }
    return l;
}

int main()
{
    long long n = 0, k = 0;
    scanf("%lld %lld", &n, &k);
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    std::sort(arr, arr + n * sizeof(long long));
    long long min = arr[n - 1];

    printf("%lld\n", solve(arr, k, n, min + 1));
    return 0;
}