#include <iostream>
#include <vector>

#define cout std::cout
#define cin std::cin
#define vector std::vector
#define endl std::endl

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (i == j)
                vec[i][j] = 0;
            else if (temp == 0)
                vec[i][j] = 1;
            else if(temp == 1)
                vec[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}