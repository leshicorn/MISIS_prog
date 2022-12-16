#include <stdio.h>
#include <stdlib.h>

#define m matrix
#define inp(a) scanf("%d", &a)
#define out(a) printf("%d", a)
#define p_p() printf(" ")
#define e_p() printf("\n")

int main()
{
    int n = 0;
    inp(n);
    int** m = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        m[i] = (int*)malloc(sizeof(int) * (n + 1));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inp(m[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += m[i][j];
        }
        out(sum);
        e_p();
    }

    return 0;
}