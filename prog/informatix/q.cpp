#include <stdio.h>
#include <iostream>
#include <string.h>

#define inp(a) scanf("%d", &a)
#define cin std::cin
#define cout std::cout
#define endl std::endl
#define MAX 110
int deg[MAX];


int main()
{
    int n = 0, m = 0;
    int a = 0, b = 0;
    scanf("%d %d", &n, &m);
    memset(deg, 0, sizeof(deg));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        deg[a]++;
        deg[b]++;
    }

    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (deg[i] != deg[i + 1])
            flag = 1;
    }

    if (flag == 0)
        cout <<"YES\n";
    else
        cout <<"NO\n";

    return 0;
}