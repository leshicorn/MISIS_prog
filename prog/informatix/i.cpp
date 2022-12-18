#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define ll long long int
#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define vector std::vector

int main()
{
    ll n = 0;
    cin >> n;
    vector<vector<ll>> vec(n + 1);
    
    for (ll i = 0; i <= n; i++)
    {
        ll temp = 0;
        string req;
        std::getline(cin, req);
        std::stringstream strm(req);
        while (strm >> temp)
        {
            vec[temp].push_back(i);
        }
    }

    cout << n << "\n";

    for (ll i = 1; i < vec.size(); i++)
    {
        for (ll j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}