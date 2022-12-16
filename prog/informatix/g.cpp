#include <iostream>

#define MAX 101

int main()
{
    int** a = (int**)malloc(sizeof(int*) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * MAX);
    }
    
    int n = 0;
    std :: cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std :: cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j])
                std :: cout << i + 1 << " " << j + 1 << "\n";

    return 0;
}