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
    memset(g, 0, sizeof(g));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }

    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (g[i][k] && g[k][j]) 
                    res &= g[i][j];
            }
        }
    }

    if (res == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}