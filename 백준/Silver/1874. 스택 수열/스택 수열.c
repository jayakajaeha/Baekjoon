#include <stdio.h>
#define M 100000
int seq[M];
int stack[M];
char ans[M*2];
int top=-1;
int idx=0;
void push(int x)
{
  stack[++top]=x;
  ans[idx++]='+';
}
void pop()
{
  top--;
  //printf("%d\n",stack[top--]);
  ans[idx++]='-';
}
int main()
{
  int n,judge=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++) scanf("%d",&seq[i]);
  int j=1;
  for(int i=0; i<n; i++)
    {
      //printf("<%d %d %d>\n",j,stack[top],seq[i]);
      if(j==seq[i])
      {
        push(j);
        pop();
        j++;
      }
      else if(j<seq[i])
      {
        while(j<=seq[i])
          {
            push(j);
            j++;
          }
        pop();
      }
      else if(stack[top]==seq[i]) pop();
      else{
        printf("NO");
        judge=1;
        break;
      }
    }
  if(judge==0)
  {
    for(int i=0; i<idx; i++) printf("%c\n",ans[i]);
  }
  return 0;
}