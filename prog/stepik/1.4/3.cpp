#include <iostream>
#include <vector>

int main()
{
    int n, m, ans = 0;
    std::cin >> n >> m;
    
    if(m == (n * (n-1))/2)
        std::cout << "YES";
    else
        std::cout << "NO";
}