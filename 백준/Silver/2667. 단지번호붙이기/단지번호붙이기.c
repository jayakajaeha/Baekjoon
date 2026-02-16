#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct ll
{
	int x, y;
	struct ll* link;
}que;

typedef struct dl
{
	int data;
	struct dl* next;
}house;

int main()
{
	int n;
	scanf("%d", &n);
	int map[27][27] = { 0 };
	int visited[729] = { 0 };
	int danji = 0;
	for (int i = 1; i <= n; i++)
	{
		getchar();
		for (int j = 1; j <= n; j++)
		{
			char tmp;
			scanf("%c", &tmp);
			map[i][j] = tmp - '0';
		}
	}
	house* num=NULL;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 1 && visited[i*(n+1) + j] == 0)
			{
				visited[i*(n+1) + j] = 1;
				house* node = (house*)malloc(sizeof(house));
				node->next = NULL;
				node->data = 1;
				que* q = (que*)malloc(sizeof(que));
				q->x = i;
				q->y = j;
				q->link = NULL;
				que* pre = q;
				while (q!=NULL)
				{
					int x=q->x, y=q->y;
					for (int k = 0; k < 4; k++)
					{
						if (map[x + dx[k]][y + dy[k]] == 1 && visited[(x + dx[k])*(n+1)+ y + dy[k]]==0)
						{
							que* new = (que*)malloc(sizeof(que));
							new->x = x + dx[k];
							new->y = y + dy[k];
							new->link = NULL;
							pre->link = new;
							pre = pre->link;
							node->data += 1;
						}
						visited[(x + dx[k])*(n+1) + y + dy[k]] = 1;
					}
					q = q->link;
				}
				// Sorting logic
				if (num == NULL || node->data <= num->data) {
					node->next = num;
					num = node;
				}
				else {
					house* pres = num;
					while (pres->next != NULL && pres->next->data < node->data) {
						pres = pres->next;
					}
					node->next = pres->next;
					pres->next = node;
				}
				//printf("(%d %d)\n", i, j);
				danji++;
			}
			visited[i*(n+1) + j] = 1;
		}
	}
	printf("%d\n",danji);
	while (num != NULL)
	{
		printf("%d\n", num->data);
		num = num->next;
	}
	return 0;
}