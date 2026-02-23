#include <stdio.h>
int main()
{
  int hash[8001]={0};
  int n,x,M=-4000,m=4000;
  double sum=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    {
      scanf("%d",&x);
      hash[x+4000]++;
      sum+=x;
      M=x>M?x:M;
      m=x<m?x:m;
    }
  int mode,mid=0,vM=0,judge=0;
  for(int i=m+4000; i<=M+4000; i++)
    {
      if(hash[i]>vM)
      {
        vM=hash[i];
        mode=i-4000;
        judge=1;
      }
      else if(hash[i]==vM&&judge<2)
      {
        mode=i-4000;
        judge++;
      }
    }
  for(int i=m+4000; i<=M+4000; i++)
    {
      if(hash[i]>0) mid+=hash[i];
      if(mid>=n/2+1) 
      {
        mid=i-4000;
        break;
      }
    }
  sum=sum<0?sum/n-0.5:sum/n+0.5;
  printf("%d\n%d\n%d\n%d",(int)sum,mid,mode,M-m);
  return 0;
}