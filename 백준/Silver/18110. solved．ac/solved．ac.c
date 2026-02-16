#include <stdio.h>
void swap(int* a, int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
void heapify(int *a, int n, int i)
{
  int p=i;
  int cl=p*2+1,cr=p*2+2;
  if(cl<n&&a[p]<a[cl]) p=cl;
  if(cr<n&&a[p]<a[cr]) p=cr;
  if(p!=i)
  {
    swap(&a[p],&a[i]);
    heapify(a, n, p);
  }
}
void heap_sort(int *a, int n)
{
  for(int i=n/2-1; i>=0; i--) heapify(a, n, i);
  for(int i=n-1; i>0; i--)
    {
      swap(&a[0], &a[i]);
      heapify(a, i, 0);
    }
}
int main()
{
  int n;
  double ridn,avg=0;
  scanf("%d",&n);
  int difficulty[n];
  ridn=(int)(n*0.15+0.5);
  for(int i=0; i<n; i++) scanf("%d",&difficulty[i]);
  heap_sort(difficulty, n);
  for(int i=ridn; i<n-ridn; i++) avg+=difficulty[i];
  avg=(avg/(n-ridn*2)+0.5);
  printf("%d",n==0?0:(int)avg);
  return 0;
}