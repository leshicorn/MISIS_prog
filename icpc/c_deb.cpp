#include <string>
#include <iostream>

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
    if (amo_6 + amo_9 == 0 || sum_str % 3 != 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    int steps = 0;

    while (sum_str % 9 != 0)
    {
        if (closest > sum_str && amo_6 > 0)
        {
            amo_6--;
            amo_9++;
            steps++;
            sum_str += 3;
        }
        if (closest > sum_str && amo_6 == 0)
        {
            closest -= 9;
            while (sum_str % 9 != 0)
            {
                sum_str -= 3;
                steps++;
                amo_9--;
                amo_6++;
            }
        }
        if (closest < sum_str && amo_9 > 0)
        {
            amo_9--;
            amo_6++;
            steps++;
            sum_str -= 3;
        }
        if (closest < sum_str && amo_9 == 0)
        {
            closest += 9;
            while (sum_str % 9 != 0)
            {
                sum_str += 3;
                steps++;
                amo_6--;
                amo_9++;
            }
        }
    }

    std::cout << steps << std::endl;
    return 0;
}