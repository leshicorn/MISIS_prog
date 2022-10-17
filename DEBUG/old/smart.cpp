#include <iostream>
#include <vector>
#include <iterator>
#include <deque>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdio.h>
#include <strings.h>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <map>

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;
typedef long long ll;
const ll mod = (1LL<<31) - 1;


int main() {
    //freopen("number.in", "r", stdin);
    //freopen("number.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<string> arr;
    string t;
    while(cin >> t)
    {
        arr.push_back(t);
    }
    for(int i = arr.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j + 1] + arr[j] > arr[j] + arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for(auto S : arr)
    {
        cout << S;
    }
    cout << endl;

    return 0;
}