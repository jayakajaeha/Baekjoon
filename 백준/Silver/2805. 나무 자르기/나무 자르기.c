#include <stdio.h>
long long trees[1000000];
int main()
{
  long long n,m,max=0;
  scanf("%lld%lld",&n,&m);
  for(int i=0; i<n; i++)\
    {
      scanf("%lld",&trees[i]);
      max=max<trees[i]?trees[i]:max;
    }
  long long start=0,end=max;
  long long mid,ans;
  while(start<=end)
    {
      long long sum=0;
      mid=(start+end)/2;
      //printf("<%lld>\n",mid);
      for(int i=0; i<n; i++)
        {
          if(mid!=0) sum+=trees[i]-mid>=0?trees[i]-mid:0;
        }
      //printf("[%lld>\n",sum);
      if(sum>=m||mid==0)
      {
        ans=mid;
        start=mid+1;
      }
      else end=mid-1;
      //printf("[%lld]\n",ans);
    }
  printf("%lld",ans);
  return 0;
}