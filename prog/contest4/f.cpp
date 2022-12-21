#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <iomanip>
#include <set>
#include <climits>


bool used[200];

int ans = 0;

void dfs(int v, std::vector<std::vector<int> >&graph) {
    ans++;
    used[v] = 1;
    for(int to = 0; to < graph[v].size(); to++) {
        if(used[to]) {
            continue;
        }
        if(graph[v][to] == 1) {
            dfs(to, graph);
        }
    }
}

int main() {
    int n, s;
    std::cin >> n >> s;
    s--;
    std::vector<std::vector<int> > graph(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    dfs(s, graph);
    std::cout << ans;

    return 0;
}