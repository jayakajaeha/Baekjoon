#include <stdio.h>
typedef struct
{
  int pzero,pone;
}fibo;
fibo cnt[41];
int end=1;
int main()
{
  int t,n;
  cnt[0].pone=0;
  cnt[1].pone=1;
  cnt[0].pzero=1;
  cnt[1].pzero=0;
  scanf("%d",&t);
  for(int i=0; i<t; i++)
    {
      scanf("%d",&n);
      if(n<=end) printf("%d %d\n",cnt[n].pzero,cnt[n].pone);
      else{
        for(end+=1; end<=n; end++)
          {
            cnt[end].pzero=cnt[end-1].pzero+cnt[end-2].pzero;
            cnt[end].pone=cnt[end-1].pone+cnt[end-2].pone;
          }
        end--;
        printf("%d %d\n",cnt[n].pzero,cnt[n].pone);
      }
    }
  return 0;
}