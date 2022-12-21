#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <iomanip>
#include <set>
#include <climits>

std::vector<int> graph[20000];
int color[200000];
bool used[200000];

void dfs(int v, int cl) {
    used[v] = 1;
    color[v] = cl;
    for(auto to : graph[v]) {
        if(used[to]) {
            continue;
        }

        dfs(to, cl);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            ans++;
            dfs(i, ans);
        }
    }

    std::cout << ans << "\n";
    for(int i = 0; i < n; i++) {
        std::cout << color[i] << " ";
    }

    return 0;
}