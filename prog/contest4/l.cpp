#include<iostream>
#include<vector>
 
std::vector<int> used;
std::vector<int> path, ans;
std::vector<std::vector<int>> g;
 
void dfs(int v){
    used[v] = true;
    path.push_back(v);
    for (auto to : g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
    if (ans.size() < path.size()){
        ans = path;
    }
    path.pop_back();
}
 
int main(){
    int n = 0;
    std::cin >> n;
    g = std::vector<std::vector<int> > (n + 1);
    for(size_t i = 0; i < n - 1; ++i){
        int u = 0, v = 0;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used = std::vector<int>(n + 1, false);
    dfs(1);
    used = std::vector<int>(n + 1, false);
    dfs(ans.back());
    std::cout << ans.size();
    return 0;
}