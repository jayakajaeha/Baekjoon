#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int white = 0, blue = 0;

void slice(int paper[][128], int n, int x,int y, int cnt)
{
	int c = 0;
	if (cnt != n*n && cnt != 0)
	{
		for (int i = x; i < n / 2+x; i++)
		{
			for (int j = y; j < n / 2+y; j++) c+=paper[i][j];
		}
		slice(paper, n / 2, x,y,c);
		
		c = 0;
		for (int i = x; i < n/2+x; i++)
		{
			for (int j = n/2+y; j < n+y; j++) c+=paper[i][j];
		}
		slice(paper, n / 2,x,y+n/2, c);
		
		c = 0;
		for (int i = n / 2 + x; i < n+x; i++)
		{
			for (int j = y; j < n/2+y; j++) c+=paper[i][j];
		}
		slice(paper, n / 2, x+n/2, y, c);

		c = 0;
		for (int i = n / 2 + x; i < n+x; i++)
		{
			for (int j = n / 2 + y; j < n+y; j++) c += paper[i][j];
		}
		slice(paper, n / 2, x+n/2, y + n / 2, c);
	}
	else
	{
		if (cnt == 0) white++;
		else blue++;
	}
}

int main()
{
	int n,cnt=0;
	scanf("%d", &n);
	int paper[128][128];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &paper[i][j]);
			cnt += paper[i][j];
		}
	}
	slice(paper, n, 0, 0, cnt);
	printf("%d\n%d", white, blue);
	return 0;
}