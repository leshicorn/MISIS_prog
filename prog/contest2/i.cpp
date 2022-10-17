#include <iostream>
#include <vector>
#include <algorithm>
 
#define BLOCK_SIZE 548

struct query
{
    int id = 0, left = 0, right = 0, result = 0;
};
 
bool cmp(const query &a, const  query &b)
{
    if (a.left / BLOCK_SIZE == b.left / BLOCK_SIZE)
        return a.right < b.right;
    return a.left < b.left;
}
 
bool cmp2(const query &a, const  query &b)
{
    return a.id < b.id;
}

std::vector<int> cnt(300001, 0);

int ans = 0;
int a = 0, b = -1;

void mo(std::vector<int>&v, query &q)
{
    int left = q.left, right = q.right;

    while(b < right)
    {
        b++;
        if (cnt[v[b]] == 0) ans++;
        cnt[v[b]]++;
    }

    while(b > right)
    {
        cnt[v[b]]--;
        if (cnt[v[b]] == 0) ans--;
        b--;
    }

    while(a < left)
    {
        cnt[v[a]]--;
        if (cnt[v[a]] == 0) ans--;
        a++;
    }

    while(a > left)
    {
        a--;
        if (cnt[v[a]] == 0) ans++;
        cnt[v[a]]++;
    }
    q.result = ans;
}
 
 
int main()
{
    int n = 0, m = 0;
    std::cin >> n;
    std::vector<int> v(n), pos;
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cin >> v[i];
    }

    pos = v;
    std::sort(pos.begin(), pos.end());

    for (size_t i = 0; i < v.size(); ++i)
    {
        v[i] = (int)(lower_bound(pos.begin(), pos.end(), v[i]) - pos.begin());
    }

    std::cin >> m;
    std::vector<query> q(m);

    for (size_t i = 0; i < q.size(); ++i)
    {
        int left = 0, right = 0;
        std::cin >> left >> right;
        q[i].id = i;
        q[i].left = left - 1;
        q[i].right = right - 1;
    }
    std::sort(q.begin(), q.end(), cmp);

    for(size_t i = 0; i < q.size(); ++i)
    {
        mo(v, q[i]);
    }
    std::sort(q.begin(), q.end(), cmp2);

    for(size_t i = 0; i < q.size(); ++i)
    {
        std::cout << q[i].result << '\n';
    }

    return 0;
}