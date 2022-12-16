#include <iostream>

#define in std::cin
#define out std::cout
#define init(a, b, c, d) int a = 0, b = 0, c = 0, d = 0;

int main()
{
    // int n = 0, m = 0;
    init(m, n, a, b);

    in >> n >> m;
    int res[n][2];
    for(int i = 0 ; i < n; i++) {
            res[i][1] = 0;
            res[i][0] = 0;
    }
    for(int i = 0; i < m; i++) {
        in >> a >> b;
        res[b - 1][0]++;
        res[a - 1][1]++;
    }
    for(int i = 0; i < n; i++) {
        out << res[i][0] << "\n" << res[i][1] << "\n";
    }
    return 0;
}