#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	int amo_i = 0, amo_s = 0;
	cin >> n;

	vector<vector<int> > arr(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					cin >> arr[i][j];
				}
		}
	for (int i = 0; i < n; i++)
		{
			int s = 0, k = 0;
			for (int j = 0; j < n; j++)
				{
					s += arr[i][j];
					k += arr[j][i];
				}
			if (s == 0)
				amo_s ++;
			if (k == 0)
				amo_i ++;
		}
	cout << amo_i << " " << amo_s << endl;
}