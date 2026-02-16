#include<stdio.h>
#include<stdlib.h>
int visited[10004]={0};
typedef struct ll
{
  int x,y;
  struct ll* link;
}que;
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int map[102][102]={{0}};
  for(int i=1; i<=n; i++)
    {
      getchar();
      for(int j=1; j<=m; j++)
        {
          char tmp;
          scanf("%c",&tmp);
          map[i][j]=tmp-'0';
        }
    }
  que* head = (que*)malloc(sizeof(que));
  head->x=1;
  head->y=1;
  head->link=NULL;
  que* pre=head;
  visited[1]=1;
  int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
  while(!(head->x==n&&head->y==m))
    {
      int x=head->x,y=head->y;
      for(int i=0; i<4; i++)
        {
          if(map[x+dx[i]][y+dy[i]]>0&&visited[(x+dx[i]-1)*m+y+dy[i]]==0)
          {
            map[x+dx[i]][y+dy[i]]=map[x][y]+1;
            que* new = (que*)malloc(sizeof(que));
            new->x=x+dx[i];
            new->y=y+dy[i];
            new->link=NULL;
            pre->link=new;
            pre=pre->link;
            visited[(pre->x-1)*m+pre->y]=1;
          }
        }
      head=head->link;
      /*
      for(int i=1; i<=n; i++)
      {
        for(int j=1; j<=m; j++)
          {
            printf("%d ",map[i][j]);
          }
        printf("\n");
      }
      printf("\n");
      */
    }
  printf("%d",map[n][m]);
  return 0;
}