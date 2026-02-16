#include<stdio.h>
#include<math.h>

void hanoi(int n, int from, int to, int aux)
{
  if(n==1)
  {
    printf("%d %d\n", from, to);
  }
  else
  {
    hanoi(n-1, from, aux, to);
    hanoi(1, from, to, aux);
    hanoi(n-1, aux, to, from);
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",(int)pow(2,n)-1);
  hanoi(n, 1, 3, 2);
  return 0;
}