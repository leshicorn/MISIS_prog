#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    int ans = array[0], ans_l = 0, ans_r = 0,
        sum = 0, min_sum = 0, min_pos = -1;
    
    for (int r=0; r<n; ++r)
    {
    	sum += array[r];
    
    	int cur = sum - min_sum;
    	if (cur > ans)
        {
    		ans = cur;
    		ans_l = min_pos + 1;
    		ans_r = r;
    	}
    
    	if (sum < min_sum)
        {
    		min_sum = sum;
    		min_pos = r;
    	}
    }

    std::cout << ans_l + 1 << " " << ans_r + 1 << " " << ans << std::endl;

    free(array);
}