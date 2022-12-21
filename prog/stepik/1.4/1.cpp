#include <iostream>
using namespace std;

int main()
{
    size_t n;
    cin >> n;

    auto matrix = new int* [n];

    for (auto i = 0U; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    for (auto i = 0U; i < n; ++i)
    {
        for (auto j = 0U; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    puts("");

    for (auto i = 0U; i < n; ++i)
    {
        for (auto j = i; j < n; ++j)
        {
            if (matrix[i][j] != 0)
            {
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }

    for (auto i = 0U; i < n; ++i)
    {
        delete[] matrix[i];
    }
    
    delete[] matrix;
}