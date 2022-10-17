#include <string>
#include <iostream>
#include <stdio.h>

int sum_string(std::string str)
{
    int sum = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        sum += str[i] - '0';
    }
    return sum;
}

int amount_of_six(std::string str)
{
    int amount = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == '6')
        {
            amount++;
        }
    }
    return amount;
}
int amount_of_nine(std::string str)
{
    int amount = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == '9')
        {
            amount++;
        }
    }
    return amount;
}

int closest_9_number(int sum)
{
    int mult = sum / 9;
    if (abs(sum - mult * 9) < abs(sum - (mult + 1) * 9))
        return mult * 9;
    return (mult + 1) * 9;
}

int main()
{
    std::string str = "";
    std::cin >> str;
    int sum_str = sum_string(str);
    int amo_6 = amount_of_six(str);
    int amo_9 = amount_of_nine(str);
    int closest = closest_9_number(sum_str);

    if (sum_str % 9 == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    /*else if (amo_6 + amo_9 == 0 || sum_str % 3 != 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }*/

    else if (closest - sum_str == -3 && amo_6 == 0 && amo_9 > 0)
    {
        printf("1\n");
        return 0;
    }
    else if (closest - sum_str == -6 && amo_6 == 0 && amo_9 > 0)
    {
        printf("2\n");
        return 0;
    }

    else if (closest - sum_str == 3 && amo_9 == 0 && amo_6 > 0)
    {
        printf("1\n");
        return 0;
    }

    else if (closest - sum_str == 6 && amo_9 == 0 && amo_6 > 0)
    {
        printf("2\n");
        return 0;
    }

    else if (closest - sum_str == 3 && amo_6 == 0 && amo_9 > 0)
    {
        printf("2\n");
        return 0;
    }
    else if (closest - sum_str == 6 && amo_6 == 0 && amo_9 > 0)
    {
        printf("1\n");
        return 0;
    }

    else if (closest - sum_str == -3 && amo_9 == 0 && amo_6 > 0)
    {
        printf("2\n");
        return 0;
    }

    else if (closest - sum_str == -6 && amo_9 == 0 && amo_6 > 0)
    {
        printf("1\n");
        return 0;
    }
    
    printf("-1\n");

    return 0;
}