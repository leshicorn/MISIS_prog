#include <algorithm>
#include <iostream>

int main()
{
    long long A = 0, K = 0, B = 0, M = 0, X = 0;
    std::cin >> A >> K >> B >> M >> X;

    long long L = 0, R = X * std::max(A, B);

    while (R - L > 1)
    {
        long long mid = (L + R) / 2;
        if ((mid - mid / K) * A + (mid - mid / M) * B >= X)
        {
            R = mid;
        }
        else
        {
            L = mid;
        }
    }
    std::cout << R << std::endl;
}