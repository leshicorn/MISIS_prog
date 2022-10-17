#include <bits/stdc++.h>

const int maxN = 1e5;

const int INF = INT_MIN;

struct SegmentsTree{
    struct node{
        int vl;
        int vr;
        int maxValue;
    };

    node* tree;

    /**
     * @brief обновляет значение в вершине через сыновей
     * 
     * @param v вершина
     */
    inline void apply(int v)
    {
        tree[v].maxValue = std :: max(tree[v * 2 + 1].maxValue, tree[v * 2 + 2].maxValue);
    }

    void build(int* arr, int v, int l, int r)
    {
        tree[v].vl = l;
        tree[v].vr = r;

        if(l == r)
        {
            tree[v].maxValue = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, v * 2 + 1, l, mid);
        build(arr, v * 2 + 2, mid + 1, r);

        apply(v);
    }

    int findMax(int v, int l, int r)
    {
        if(tree[v].vl > r || tree[v].vr < l)
            return INF;

        if(l <= tree[v].vl && tree[v].vr <= r)
            return tree[v].maxValue;

        int ql = findMax(v * 2 + 1, l, r);
        int qr = findMax(v * 2 + 2, l, r);
        return std :: max(ql, qr);
    }

    void modif(int v, int pos, int x)
    {
        if(tree[v].vl == tree[v].vr)
        {
            tree[v].maxValue = x;
            return;
        }

        int mid = (tree[v].vl + tree[v].vr) / 2;
        if(pos <= mid)
            modif(v * 2 + 1, pos, x);
        else
            modif(v * 2 + 2, pos, x);

        apply(v);
    }

    /**
     * @brief Construct a new Segments Tree object
     * 
     * @param arr 
     * @param n 
     */
    SegmentsTree(int* arr, int n)
    {
        tree = (node*) malloc(sizeof(node) * n * 4);
        build(arr, 0, 0, n - 1);
    }
    
    /**
     * @brief Destroy the Segments Tree object
     * 
     */
    ~SegmentsTree()
    {
        free(tree);
        tree = nullptr;
    }
};

int main(){
    std :: ios_base::sync_with_stdio(false);
    std :: cin.tie(0);
    std :: cout.tie(0);
    int n, q;
    std :: cin >> n;
    int* arr = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        std :: cin >> arr[i];
    }

    SegmentsTree myTree = SegmentsTree(arr, n);

    std:: cin >> q;

    for(int i = 0; i < q; i++)
    {
        int l, r;
        std :: cin >> l >> r;
        std :: cout << myTree.findMax(0, l - 1, r - 1) << " ";
    }

	free(arr);
    return 0;
}