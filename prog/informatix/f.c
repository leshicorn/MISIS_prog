#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define am adjacency_matrix
#define MAX 101

int main()
{
    int n = 0, m = 0;
    scanf("%d %d",&n,&m);
    int** am = (int**)malloc(sizeof(int*) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        am[i] = (int*)malloc(sizeof(int) * MAX);
    }

    memset(am, 0, sizeof(am));
    
    for(int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d",&a,&b);
        am[a][b] = am[b][a] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ",am[i][j]);
        }
        printf("\n");
    }

    return 0;
}