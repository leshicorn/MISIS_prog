#include <iostream>

#define inp std::cin
#define out std::cout

int main()
{
    int n = 0;
    inp >> n;
    int a[n][n], s[n], c[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inp >> a[i][j];
        }
    }

    for(int j=0;j< n;j++)
    {
        s[j]=0;
        for(int i=0;i< n;i++)
        {
            s[j] = s[j] + a[i][j];
        }
    }

    for(int i=0;i< n;i++)
    {
        c[i]=0;
        for(int j=0;j< n;j++)
            c[i]=c[i]+a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        out << s[i] << "\n" << c[i] << "\n";
    }
}