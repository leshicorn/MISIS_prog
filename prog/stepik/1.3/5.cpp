#include <iostream>
#include <vector>

#define cin std::cin
#define cout std::cout
#define vector std::vector
#define endl std::endl
#define pair std::pair

int main()
{
    int n, m, k, ans = -1;
    cin >> n >> m;
    vector<pair<int, int>> pairs(m, pair<int, int>(0, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> pairs[i].first >> pairs[i].second;
    }
    cin >> k;
    k--;
    for (int i = 0; i < m; i++)
    {
        if (pairs[k].first == pairs[i].first || pairs[k].second == pairs[i].second || pairs[k].second == pairs[i].first || pairs[k].first == pairs[i].second)
            ans++;
    }

    cout << ans << endl;
}