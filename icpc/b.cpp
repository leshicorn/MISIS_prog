#include <iostream>

bool check_triangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
        return true;
    return false;
}

int main()
{
    int* array = new int[4];
    for (int i = 0; i < 4; i++)
    {
        std::cin >> array[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            for (int k = 2; k < 4; k++)
            {
                for (int l = 3; l < 4; l++)
                {
                    if (check_triangle(array[i], array[j], array[k] + array[l]))
                        std::cout << "TRUE" << std::endl;
                }
            }
        }
    }
}