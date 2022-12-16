#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define MAX 101
int g[MAX][MAX];

int main()
{
    int n = 0, m = 0, a = 0, b = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b]++;
    }

    int flag = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i != j) && (g[i][j] + g[j][i]!= 1))
                flag = 1;
        }
    }

    if (flag == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}