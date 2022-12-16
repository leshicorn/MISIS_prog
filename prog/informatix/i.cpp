#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#define MAX 50001
#define INPUT_ERROR -1
#define g adjacency_matrix
char s[MAX];
std::vector<std::vector<int>> g;

int main()
{
    int n = 0;

    scanf("%d",&n); 
    fgets(s, sizeof(s), stdin);
    if (s == NULL) return INPUT_ERROR;
    g.resize(n + 1);

    for(int i = 1; i <= n; i++)
    {
        fgets(s, sizeof(s), stdin);
        std::stringstream ss(s);
          while (ss >> val)
          g[val].push_back(i);

}
}