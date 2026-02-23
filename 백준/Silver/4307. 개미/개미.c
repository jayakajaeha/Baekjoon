#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int l, n;
		scanf("%d%d", &l, &n);
		int m = 0, M = 0;
		for (int j = 0; j < n; j++)
		{
			int loc;
			scanf("%d", &loc);
			if (loc < l / 2)
			{
				if (loc > m) m = loc;
				if (l - loc > M) M = l - loc;
			}
			else
			{
				if (l - loc > m) m = l-loc;
				if (loc > M) M = loc;
			}
		}
		printf("%d %d\n", m, M);
	}
	return 0;
}
