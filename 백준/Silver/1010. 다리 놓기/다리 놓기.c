#include <stdio.h>
int main()
{
  int t,n,m;
  int dp[30][30]={{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d%d",&n,&m);
      if(m>4)
      {
        for(int i=4; i<m; i++)
          {
            dp[i][0]=1,dp[i][i+1]=1;
            for(int j=1; j<i+1; j++)
              {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
              }
          }
      }
      printf("%d\n",dp[m-1][n]);
    }
  return 0;
}