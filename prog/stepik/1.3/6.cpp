#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main() 
{
    int n;
    cin >> n;
    vector<vector <int>> v(n, vector<int>(n,0));
    vector<vector <int>> l(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                l[i][j] = 0;
            }
            else {
                if (i != j) {
                    l[i][j] = 1;
                }
                else {
                    l[i][j] = 0;
                }
            }
            cout << l[i][j] << " ";
        }
        cout << endl;
    }
}