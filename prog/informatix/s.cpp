#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long int ll;

std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> rez;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int count = 0;
    int rebro = 0;
    int sum = 0;

    std::cin >> rebro >> count;
    arr = std::vector<std::vector<int>>(count, std::vector<int>(2));
    rez = std::vector<std::vector<int>>(rebro, std::vector<int>(rebro));

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> arr[i][j];
            if (j == 1) {
                rez[arr[i][j - 1] - 1][arr[i][j] - 1] = 1;
                rez[arr[i][j] - 1][arr[i][j - 1] - 1] = 1;
            }
        }
    }
    for (int i = 0; i < rebro; i++) {
        for (int j = 0; j < rebro; j++) {
            if (rez[i][j] == 0 && i != j) sum = 1;
        }
    }
    if (sum == 0) std::cout << "YES" << "\n";
    else std::cout << "NO" << "\n";

    return 0;
}