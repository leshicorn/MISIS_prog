#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <iomanip>

struct edge {
    int from;
    int to;
    long long weight;
    bool operator<(edge& other) {
        return weight < other.weight;
    }
};


class DSU{
public:
    DSU(int n) {
        dsu.resize(n);
        rnk.resize(n);
        for(int i = 0; i < n; i++) {
            dsu[i] = i;
            rnk[i] = 1;
        }
    }

    int get(int v) {
        if(v == dsu[v]) {
            return v;
        }

        return dsu[v] = get(dsu[v]);
    }

    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if(a == b) {
            return;
        }

        if(rnk[b] < rnk[a]) {
            std::swap(a, b);
        }

        dsu[b] = a;
        rnk[a] += rnk[b];
    }

private:
    std::vector<int> dsu;
    std::vector<int> rnk;
};


int main() {
    int n, m;
    std::cin >> n >> m;
    int cntCom = n;
    std::vector<edge> edges(m);
    for(int i = 0; i < m; i++) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    std::sort(edges.begin(), edges.end());
    long long ans = 0;
    
    DSU curDsu(n);
    for(auto e : edges) {
        int from = e.from;
        int to = e.to;
        if(curDsu.get(from) != curDsu.get(to)) {
            ans += e.weight;
            curDsu.merge(from, to);
            cntCom--;
        }
    }   

    if(cntCom != 1) {
        std::cout << "NON-CONNECTED";
        return 0;
    }

    std::cout << ans;

    return 0;
}