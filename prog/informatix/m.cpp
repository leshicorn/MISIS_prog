#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define am adjacency_matrix
#define MAX 101
#define inp(a) scanf("%d", &a)
#define out(a) printf("%d", a)
#define p_p() printf(" ")
#define e_p() printf("\n")


int main()
{
    int n = 0, m = 0;
    scanf("%d %d",&n,&m);
    int am[MAX][MAX];

    memset(am, 0, sizeof(am));
    
    for(int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        am[a - 1][b - 1] = am[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += am[i][j];
        }
        out(sum);
        e_p();
    }

    return 0;
}