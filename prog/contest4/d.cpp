#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <string>

struct query{
    std::string type;
    int from;
    int to;
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

    int getLider(int v) {
        if(dsu[v] == v) {
            return v;
        }

        return dsu[v] = getLider(dsu[v]);
    }

    void merge(int a, int b) {
        a = getLider(a);
        b = getLider(b);
        if(a == b) {
            return;
        }

        if(rnk[a] > rnk[b]) {
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
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::pair<int,int> > edges(m);
    for(int i = 0; i < m; i++) {
        std::cin >> edges[i].first >> edges[i].second;
    }

    std::vector<query> queries(q);

    for(int i = 0; i < q; i++) {
        std::cin >> queries[i].type >> queries[i].from >> queries[i].to;
    }

    DSU curDsu(n + 1);

    std::vector<std::string> ans;
    for(int i = queries.size() - 1; i >= 0; i--) {
        if(queries[i].type == "ask") {
            int v = queries[i].from;
            int u = queries[i].to;
            if(curDsu.getLider(v) != curDsu.getLider(u)) {
                ans.push_back("NO");
            }
            else {
                ans.push_back("YES");
            }
        }
        else {
            int v = queries[i].from;
            int u = queries[i].to;
            curDsu.merge(v, u);
        }
    }

    for(int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}