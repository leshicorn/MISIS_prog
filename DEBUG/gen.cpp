#include <bits/stdc++.h>

using namespace std;

int main(int args, char* argv[])
{
	int seed = atoi(argv[1]);
	mt19937 rnd(seed);

	int n = 100;
	for(int i = 0; i < n; i++)
	{
		int len = 100;
		for(int j = 0; j < len; j++)
		{
			int type = rnd() % 10;
			cout << type;
		}
		cout << endl;
	}
	return 0;
}