#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <iomanip>
#include <set>
#include <climits>

std::vector<int> graph[200];
bool used[200];

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    s--;

    for(int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }

    std::queue<int> q;
    q.push(s);
    std::vector<int> ans;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if(used[v]) {
            continue;
        }
        ans.push_back(v + 1);
        used[v] = 1;
        for(auto to : graph[v]) {
            if(!used[to]) {
                q.push(to);
            }
        }
    }

    std::cout << ans.size() << "\n";
    for(auto v : ans) {
        std::cout << v << " ";
    }

    return 0;
}