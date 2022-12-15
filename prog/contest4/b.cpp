#include <stdio.h>

#define INPUT_ERROR 1
#define DATA_ERROR 2
#define MAX_I 10000

int main(void) {
	int N;
	int M;

	if (scanf("%d %d", &N, &M) != 2) 
		return INPUT_ERROR;
	if ((N <= 0) || (N > MAX_I)) 
		return DATA_ERROR;

	if (N == 1) 
	{
		printf("%d", 0);
		return 0;
	}

	int color = 1;
	int diff = 0;
	int bridge = 0;
	int painted = 0;
	int i[MAX_I];
	int k;

	for (k = 0; k < N; k++)
		i[k] = 0;

	while (bridge < M)
	{
		int from, to;
		if (scanf("%d %d", &from, &to) != 2) 
			return INPUT_ERROR;
		if ((from <= 0) || (from > N)) 
			return DATA_ERROR;
		if ((to <= 0) || (to > N)) 
			return DATA_ERROR;
		bridge++;

		if (from == to)
			continue;

		if ((i[from] + i[to]) == 0)
		{
			i[from] = i[to] = color;
			color++;
			painted += 2;
			diff++;
		}
		else if (i[from] == i[to])
		{
			continue;
		}
		else if (i[from] == 0)
		{
			i[from] = i[to];
			painted++;
		}
		else if (i[to] == 0)
		{
			i[to] = i[from];
			painted++;
		}
		else
		{
			int from_color = i[from];
			int to_color = i[to];
			for (k = 0; k < N; k++)
				if (i[k] == from_color)
					i[k] = to_color;
			diff--;
		}
		if ((painted == N) && (diff == 1))
		{
			printf("\n%d\n", bridge);
			return 0;
		}
	}
	printf("%d", -1);
	return 0;
}