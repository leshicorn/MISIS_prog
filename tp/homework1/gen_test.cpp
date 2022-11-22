#include <stdio.h>
#include <time.h>
#include <iostream>

#define OPEN_ERROR -1

void gen_tests(int n, FILE* fp)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", rand() % n);
    }
}

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    
    FILE* fp;;
    if ((fp = fopen("test.txt", "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return OPEN_ERROR;
    }

    int n = rand() % (2 * (10 * 10 * 10 * 10 * 10));
    fprintf(fp, "%d\n", n);
    gen_tests(n, fp);
    fclose(fp);

    return 0;
}