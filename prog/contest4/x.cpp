#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using std::vector;

struct str{
    int v;
    float tyt, tam;
    int pos;
};
vector< vector< str > > g;

vector< float > dp(105, -1e9);

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
    int n, m, s; std::cin >> n >> m >> s;
    float val; std::cin >> val;
    g = vector< vector< str > >(n);
    s--;
    for(int i = 0; i < m; i++){
        int u, v; std::cin >> u >> v;
        u--; v--;
        float tyt, tam; std::cin >> tyt >> tam;
        g[u].push_back({v, tyt, tam, i});
        std::cin >> tyt >> tam;
        g[v].push_back({u, tyt, tam, i});
    }
    std::set< std::pair< float, int > > ss;
    ss.insert({val, s});
    dp[s] = val;
    while(!ss.empty()){
        auto it = ss.end(); it--;
        std::pair< float, int > cur = *it;
        ss.erase(it);
        if(dp[s] > val){
            std::cout << "YES";
            return 0;
        }
        for(auto to: g[cur.second]){
             float sum = (cur.first - to.tam) * to.tyt;
            //std::cout << cur.first << ' ' << sum << ' ' << cur.second << ' ' << to.v << "\n";
            if(dp[to.v] < sum){
                dp[to.v] = sum;
                ss.insert({dp[to.v], to.v});
            }
        }
    }
    std::cout << "NO";
}