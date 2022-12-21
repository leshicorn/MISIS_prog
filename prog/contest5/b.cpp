#include <stdio.h>
#include <stdlib.h>

#define ALLOCATION_ERROR -1

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc((n + 1) * sizeof(int));
    if (arr == NULL) return ALLOCATION_ERROR;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i / 2] + arr[i / 2 - 1];
        }
        else
        {
            arr[i] = arr[(i - 1) / 2] - arr[(i - 1) / 2 - 1];
        }
    }

    printf("%d\n", arr[n]);

    return 0;
}