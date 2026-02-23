#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int heap[100000];
int idx = 0;
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int* a, int n, int i)
{
	int p = i;
	int cl = p * 2 + 1, cr = p * 2 + 2;
	if (cl < n&&a[cl] < a[p]) p = cl;
	if (cr < n&&a[cr] < a[p]) p = cr;
	if (p != i)
	{
		swap(&a[p], &a[i]);
		heapify(a, n, p);
	}
}

void insert(int x)
{
	int tmp_idx = idx;
	int tmp;
	heap[idx++] = x;
	while (tmp_idx > 0)
	{
		if (heap[(tmp_idx -1)/ 2] > heap[tmp_idx])
		{
			swap(&heap[(tmp_idx-1) / 2], &heap[tmp_idx]);
			tmp_idx =(tmp_idx-1)/ 2;
		}
		else break;
	}
}

int main()
{
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			if(idx==0) printf("0\n");
			else
			{
				printf("%d\n", heap[0]);
				heap[0] = heap[idx - 1];
				heapify(heap, idx, 0);
				idx--;
			}
		}
		else
		{
			insert(x);
		}
	}
	return 0;
}