#include <stdio.h>
int main()
{
  int k,n,max=1,ans;
  scanf("%d%d",&k,&n);
  int kl[k];
  for(int i=0; i<k; i++)
    {
      scanf("%d",&kl[i]);
      max=kl[i]>max?kl[i]:max;
    }
  long long start=1,end=max;
  long long mid;
  while(start<=end)
    { 
      mid=(start+end)/2;
      int sum=0;
      for(int i=0; i<k; i++) sum+=kl[i]/mid;
      if(sum>=n)
      {
        ans=mid;
        start=mid+1;
      }
      else end=mid-1;
    }
  printf("%d",ans);
  return 0;
}