#include <stdio.h>
int farm[50][50]={0};
int m,n;
void dfs(int x, int y)
{
  farm[y][x]=0;
  if(x+1<m&&farm[y][x+1]) dfs(x+1,y);
  if(x>0&&farm[y][x-1]) dfs(x-1,y);
  if(y+1<n&&farm[y+1][x]) dfs(x,y+1);
  if(y>0&&farm[y-1][x]) dfs(x,y-1);
}
int main()
{
  int t,x,y,k;
  scanf("%d",&t);
  for(int i=0; i<t; i++)
    {
      scanf("%d%d%d",&m,&n,&k);
      for(int j=0; j<k; j++)
        {
          scanf("%d%d",&x,&y);
          farm[y][x]=1;
        }
      int cnt=0;
      for(int p=0; p<n; p++)
        {
          for(int q=0; q<m; q++)
            {
              if(farm[p][q])
              {
                dfs(q,p);
                cnt++;
              }
            }
        }
      printf("%d\n",cnt);
    }
  return 0;
}