#include <stdio.h>
int circle[1000000];
int main()
{
  int t;
  scanf("%d",&t);
  for(int i=0; i<t; i++)
    {
      int a,b,idx=1;
      scanf("%d%d",&a,&b);
      circle[0]=a%10;
      if(a%10==0) printf("10\n");
      else{
        int a1=a%10*a;
        while(a1%10!=circle[0])
          {
            circle[idx++]=a1%10;
            a1=a1%10*a;
          }
        printf("%d\n",b%idx==0?circle[idx-1]:circle[b%idx-1]);
      }
    }
  return 0;
}