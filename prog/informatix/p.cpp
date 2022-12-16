#include <iostream>
#include <vector>

#define cin std::cin
#define cout std::cout
#define ya_ustal_eto_pisat std::vector
#define endl std::endl

#define MAX 101

int main()
{
	int n = 0;
	int amo_i = 0, amo_s = 0;
	cin >> n;
    int is[MAX], is_ind = 0;
    int st[MAX], st_ind = 0;


	ya_ustal_eto_pisat<ya_ustal_eto_pisat<int>> arr(n + 1, ya_ustal_eto_pisat<int>(n + 1));
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
        {
			amo_s++;
            st[st_ind] = i;
            st_ind++;
            // cout << i << endl;
        }
		if (k == 0)
        {
			amo_i++;
            is[is_ind] = i;
            is_ind++;
            // cout << i << endl;
        }
	}
    
    cout << amo_i << endl;
    for (int i = 0; i < is_ind; i++)
    {
        cout << is[i] + 1 << endl;
    }

    cout << amo_s << endl;
    for (int i = 0; i < st_ind; i++)
    {
        cout << st[i] + 1 << endl;
    }

    return 0;
}