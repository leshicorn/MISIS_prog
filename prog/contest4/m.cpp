#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <iomanip>

std::vector<int> graph[100];
int depth[100];

void dfs(int v, int pr, int k) {
    depth[v] = k;
    for(auto to : graph[v]) {
        if(to == pr) {
            continue;
        }
        dfs(to, v, k + 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int pr;
        std::cin >> pr;
        pr--;
        graph[pr].push_back(i + 1);
        graph[i + 1].push_back(pr);
    }

    dfs(0, -1, 0);

    int maxV = 0;
    for(int i = 0; i < n; i++) {
        maxV = std::max(maxV, depth[i]);
    }

    std::vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(maxV == depth[i]) {
            ans.push_back(i);
        }
    }

    std::cout << maxV << "\n";
    std::cout << ans.size() << "\n";
    for(auto v : ans) {
        std::cout << v + 1 << " ";
    }

    return 0;
}