#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int t,max=5;
	long long ct[5002] = { 1,1,2,5,14 };
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int e;
		scanf("%d", &e);
		for (int i = max; i <= e+1; i++)
		{
			long long tmp = 0;
			for (int j = 0; j<i; j++)
			{
				tmp += (ct[j] * ct[i - 1 - j])% 1000000007;
			}
			ct[i] =tmp%1000000007;
		}
		if (e+1 > max) max = e+1;
		printf("%lld\n", ct[e+1]);
	}
	return 0;
}