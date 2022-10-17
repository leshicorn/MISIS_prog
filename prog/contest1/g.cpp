#include <iostream>
#include <vector>
#include <algorithm>

bool is_true(std::vector<long long> arr, long long k, long long max)
{
    long long x = 0;
    for (long long i = 0; i < arr.size(); i++)
    {
        x += arr[i] / max;
        if(x >= k) return true;
    }
    return false;
}

long long solve(long long r, std::vector<long long> arr, long long k)
{
    long long l = 0, mid = 0;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (is_true(arr, k, mid))
        {
            l = mid;
        }
        else r = mid;
    }
    return l;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<long long> arr(n);

    for(long long i = 0; i < n; i++) {
        std::cin >> arr[i];
        // arr.push_back(input_variable);
    }

    std::sort(arr.begin(), arr.end());
    long long min = arr[arr.size()-1];

    std::cout << solve(min + 1, arr, k) << std::endl;
    arr.clear();
    return 0;
}