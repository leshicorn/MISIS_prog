#include <iostream>


#define cin std::cin
#define cout std::cout
#define endl std::endl


int main()
{
    int n;
    cin >> n;
    bool arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                for (int z = 0; z < n; z++)
                {
                    if (arr[j][z] && !arr[i][z])
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "YES" << endl;
    return 0;
}