#include <stdio.h>
#include <stdlib.h>
int graph[1001][1001]={0};
int visited[1001]={0};
int que[1000];
int h=-1,t=-1;
int isEmpty()
{
  if(h>=t) return 1;
  return 0;
}
void push(int n)
{
  if(isEmpty())
  {
    h=0;
    t=0;
    que[t++]=n;
  }
  else if(t==999)
  {
    que[t]=n;
    t=0;
  }
  else que[t++]=n;
}
int pop()
{
  if(isEmpty()) return 0;
  else if(h==999)
  {
    h=0;
    return que[999];
  }
  else return que[h++];
}
void ae(int u,int v)
{
  graph[u][v]=1;
  graph[v][u]=1;
}
void DFS(int v,int n)
{
  visited[v]=1;
  for(int i=1; i<=n; i++)
    {
      if(graph[v][i]&&!visited[i])
      {
        printf("%d ",i);
        DFS(i,n);
      }
    }
}
void BFS(int v, int n)
{
  visited[v]=1;
  for(int i=1; i<=n; i++)
    {
      if(graph[v][i]&&!visited[i])
      {
        printf("%d ",i);
        visited[i]=1;
        push(i);
      }
    }
  if(!isEmpty()) BFS(pop(),n);
}
int main()
{
  int n,m,v;
  scanf("%d%d%d",&n,&m,&v);
  for(int i=0; i<m; i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      ae(u,v);
    }
  printf("%d ",v);
  DFS(v,n);
  printf("\n%d ",v);
  for(int i=1; i<1001; i++) visited[i]=0;
  BFS(v,n);
  return 0;
}