#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <iomanip>
#include <set>
#include <climits>



int main() {
    int n, s, f;
    std::cin >> n >> s >> f;
    std::vector<std::vector<int> > graph(n + 1, std::vector<int>(n + 1,-1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    s--; f--;

    std::set<std::pair<int,int> > q;
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> pr(n, -1);
    dist[s] = 0;
    q.insert({0, s});
    while(!q.empty()) {
        std::pair<int,int> pn = *q.begin();
        q.erase(q.begin());
        int v = pn.second;
        int curW = pn.first;
        if(curW > dist[v]) {
            continue;
        } 

        for(int to = 0; to < n; to++) {
            if(graph[v][to] == -1)
                continue;

            int w = graph[v][to];
            if(dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                q.insert({dist[to], to}); 
                pr[to] = v;
            } 
        }
    }

    if(dist[f] == INT_MAX) {
        std::cout << -1;
        return 0;
    }

    std::vector<int> ans;
    int curV = f;
    while(curV != -1) {
        ans.push_back(curV + 1);
        curV = pr[curV];
    }
    std::reverse(ans.begin(), ans.end());

    for(auto v : ans) {
        std::cout << v << " ";
    }

    return 0;
}