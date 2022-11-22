#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>

typedef struct ans
{
    int x1, y1, x2, y2;
    int ans;
} answer;



int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int** pref = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        pref[i] = (int*)malloc(sizeof(int) * m);
    
    }

    pref[0][0] = arr[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            pref[i][j] = arr[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }

    answer ans;
    ans.ans = INT_MIN;

    for (int x1 = 0; x1 < n; x1++)
    {
        for (int y1 = 0; y1 < m; y1++)
        {
            for (int x2 = x1; x2 < n; x2++)
            {
                for (int y2 = y1; y2 <= m; y2++)
                {
                    int summm = 0;
                    if (x1 == 0 && y1 == 0) summm = pref[x2][y2];
                    else if (x1 == 0) summm = pref[x2][y2] - pref[x2][y1 - 1];
                    else if (y1 == 0) summm = pref[x2][y2] - pref[x1 - 1][y2];
                    else summm = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
                    std::cout<<summm<<" ";
                    if (summm > ans.ans)
                    {
                        ans.ans = summm;
                        ans.x1 = x1;
                        ans.x2 = x2;
                        ans.y1 = y1;
                        ans.y2 = y2;
                    }
                }
            }
        }
    }

    printf("%d\n", ans.ans);
    printf("x1: %d y1: %d\n x2: %d y2: %d\n", ans.x1, ans.y1, ans.x2, ans.y2);

    // printf("%d\n", summ(arr, pref, ans.x1, ans.x2, ans.y1, ans.y2));
    return 0;
}