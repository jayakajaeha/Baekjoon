#include <stdio.h>
int main()
{
  int n,m,min=64,idx=0,cnt=0;
  char wb[2]={'W','B'};
  scanf("%d%d",&n,&m);
  getchar();
  char b[n][m+1];
  for(int i=0; i<n; i++) scanf("%s",b[i]);
  for(int i=0; i<n-7; i++)
    {
      for(int p=0; p<m-7; p++)
        {
          cnt=0;
          for(int j=i; j<i+8; j++)
            {
              for(int q=p; q<p+8; q++)
                {
                  if (wb[idx%2]!=b[j][q]) cnt++;
                  idx++;
                }
              idx++;
            }
          cnt=cnt>32?64-cnt:cnt;
          min=cnt<min?cnt:min;
        } 
    }
  printf("%d",min);
}