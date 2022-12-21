#include<iostream>
#include<string>
#include<vector>
 
class Dsu{
private:
    std::vector<int> p;
 
public:
    Dsu(int size = 10){
        p = std::vector<int>(size, -1);
    }
 
    int find(int v){
        int r = v;
        while (p[r] != -1){
            r = p[r];
        }
        while(v != r){
            int tmp = p[v];
            p[v] = r;
            v = tmp;
        }
        return r;
    }
 
    void join(int a, int b){
        p[find(a)] = find(b);
    }
 
    bool check(int a, int b){
        return find(a) == find(b);
    }
 
};
 
 
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string cmd;
    Dsu dsu;
    while (std::cin >> cmd){
        if (cmd == "RESET"){
            int sz = 0;
            std::cin >> sz;
            dsu = Dsu(sz);
            std::cout << "RESET DONE\n";
 
        } else if (cmd == "JOIN"){
            int a = 0, b = 0;
            std::cin >> a >> b;
            if (dsu.check(a, b)){
                std::cout << "ALREADY " << a << ' ' << b << '\n';
            } else {
                dsu.join(a, b);
            }
        } else if (cmd == "CHECK"){
            int a = 0, b = 0;
            std::cin >> a >> b;
            if (dsu.check(a, b)){
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}   