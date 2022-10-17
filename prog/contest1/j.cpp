#include <stdio.h>
#include <stdlib.h>

int heaplify(int *array, int len, int index);
int build_heap(int *array, int len);

int heapsort(int *array,int len)
{
    build_heap(array, len);
    int tmp = 0;
    int newlen = len;

    while (newlen > 1)
    {
        tmp = array[0];
        array[0] = array[newlen - 1];
        array[newlen - 1] = tmp;
        newlen--;
        heaplify(array, newlen, 0);
    }
    return 0;
}

int build_heap(int *array,int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        if(2 * i + 1 > len - 1) continue;
        heaplify(array, len, i);
    }
    return 0;
}
int heaplify(int *array, int len, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int tmp = 0;

    if (left > len - 1)
    {
        return 0;
    }

    else if  (left == len - 1)
    {
        if (array[index] < array[left])
        {
            tmp = array[index];
            array[index] = array[left];
            array[left] = tmp;
        }
        return 0;
    }
    else
    {
        if (array[index] < array[left] || array[index] < array[right])
        {
            if (array[left] < array[right])
            {
                tmp = array[index];
                array[index] = array[right];
                array[right] = tmp;
                heaplify(array, len, right);
            }
            else
            {
                tmp = array[index];
                array[index] = array[left];
                array[left] = tmp;
                heaplify(array, len, left);
            }
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}