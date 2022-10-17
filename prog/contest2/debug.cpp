#include <stdio.h>

int a_b_out(int n)
{
    if (n < 1)
    return 1;
    a_b_out(n - 1);
    printf("%d ", n);
}

int main()
{
    a_b_out(5);
    printf("\n");
    return 0;
}