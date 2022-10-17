#include <iostream>
#include <algorithm>
#include <vector>

int amount_of_strings(int n)
{
    return (n - 4) + 1;
}

int main()
{
    int n = 0;
    std::cin >> n;



}

/*
    Нужна строка длины 4, состоящая из 1 * 0, и 3 * 2
    0222
    2022
    2202
    2220
    
    Если длина = 5:
    02220
    20222
    22022
    22202

    Если длина = 6:
    022202
    202220
    220222
    222022

*/