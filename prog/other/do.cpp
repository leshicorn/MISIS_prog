#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>


#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define MAXN = 100000
#define v vershina


int xor_calc(int a, int b)
{
	return (a ^ b);
}

int find_mid(int a, int b)
{
	return (a + b) / 2;
}

struct segments_tree
{
	struct node
	{
		int vl, vr;
		int maxValue, xorv;
	};

	node* segment_tree;

	/**
	 * @brief обновляет значение в вершине через сыновей
	 * 
	 * @param v вершина
	 */
	inline void update_versh_value(int v)
	{
		segment_tree[v].maxValue = std::max(segment_tree[2 * v + 1].maxValue, segment_tree[2 * v + 2].maxValue);
		segment_tree[v].xorv = xor_calc(segment_tree[2 * v + 1].xorv, segment_tree[2 * v + 2].xorv);
	}

	/**
	 * @brief build(arr, 0, 0, n - 1);
	 * 
	 * @param arr массив чисел
	 * @param v при запуске вершина 0
	 * @param l при запуске 0
	 * @param r при запуске n - 1
	 */
	void build(int* arr, int v, int l, int r)
	{
		segment_tree[v].vl = l;
		segment_tree[v].vr = r;

		if (r == l)
		{
			segment_tree[v].maxValue = arr[r];
			segment_tree[v].xorv = arr[r];
			return;
		}
		int mid = find_mid(r, l);
		build(arr, v * 2 + 1, l, mid);
		build(arr, v * 2 + 2, mid + 1, r);

		update_versh_value(v);
	}

	int xor_na_otr(int l, int r, int v)
	{
		if (segment_tree[v].vr < l || segment_tree[v].vl > r) return 0;
		if (segment_tree[v].vr <= r && segment_tree[v].vl >= l) return segment_tree[v].xorv;

		int go_left = xor_na_otr(l, r, 2 * v + 1);
		int go_right = xor_na_otr(l, r, 2 * v + 2);

		return xor_calc(go_right, go_left);
	}

	int max_na_otr(int l, int r, int v)
	{
		if (segment_tree[v].vl > r || segment_tree[v].vr < l) return INT_MIN;
		if (segment_tree[v].vl >= l && segment_tree[v].vr <= r) return segment_tree[v].maxValue;

		int go_left = max_na_otr(l, r, 2 * v + 1);
		int go_right = max_na_otr(l, r, 2 * v + 2);
		
		return std::max(go_right, go_left);
	}

	void change_value_on_pos(int v, int position, int x)
	{
		if (segment_tree[v].vl == segment_tree[v].vr)
		{
			segment_tree[v].maxValue = x;
			segment_tree[v].xorv = x;
			return;
		}

		int mid = find_mid(segment_tree[v].vl, segment_tree[v].vr);

		if (position > mid)
		{
			change_value_on_pos(2 * v + 2, position, x);
		}
		else
		{
			change_value_on_pos(2 * v + 1, position, x);
		}
		update_versh_value(v);
	}

	/**
	 * @brief Consegment_treeruct a new segments tree object
	 * 
	 * @param arr array of numbers
	 * @param size size of array
	 */
	segments_tree(int* arr, int size)
	{
		segment_tree = new node[size * 4];
		build(arr, 0, 0, size - 1);
	}

	/**
	 * @brief Desegment_treeroy the segments tree object
	 */
	~segments_tree()
	{
		free(segment_tree);
		segment_tree = NULL;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
	int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
	}

	segments_tree tree = segments_tree(arr, N);

	// std::cout << tree.segment_tree[0].maxValue << std::endl;

	for (int i = 0; i < M; i++)
	{
		int left, right, position, number, type;
		std::cin >> type;

		switch (type)
		{
			case 1:
			{
				std::cin >> left >> right;
				std::cout << tree.xor_na_otr(left, right, 0) << std::endl;
				break;
			}
			case 2:
			{
				std::cin >> left >> right;
				std::cout << tree.max_na_otr(left, right, 0) << std::endl;
				break;
			}
			case 3:
			{
				std::cin >> position >> number;
				tree.change_value_on_pos(0, position, number);
				break;
			}
			default:
			{
				return -1;
				break;
			}
		}
	}
	return 0;
}