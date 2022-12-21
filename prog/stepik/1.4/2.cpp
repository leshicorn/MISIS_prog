#include <iostream>

int amo_diff(std::size_t* mas, int n)
{
 std::size_t count = 0;
    for (int  i = 0; i < n; i++)
    {
        int j = 0;
        while (j < i && mas[j] != mas[i]) ++j;
 
        count += j == i;
    }
    return count;
}

int main() {
 
    std::size_t vertexCount;
    std::cin >> vertexCount;
 
    std::size_t edgeCount;
    std::cin >> edgeCount;
 
    std::size_t *vertexPowers = new std::size_t[vertexCount]{};
    edgeCount *= 2;
    for (std::size_t edge; (edgeCount > 0) && (std::cin >> edge); --edgeCount) {
        ++vertexPowers[edge - 1];
    }
    

    std::cout << amo_diff(vertexPowers, vertexCount) << "\n";
    
    delete[] vertexPowers;
    return 0;
}