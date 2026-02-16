#include<stdio.h>
#include<math.h>
int axis0=0, axis1=0;
int ren(int n,int a)
{
  while(!(pow(2,n-1)<=a)) return ren(n-1,a);
  return n;
}
int z(int n, int r, int c, int min)
{
  int time=(int)pow(pow(2,n-1),2);
  if(n>0)
  {
    if(r<axis0+(int)pow(2,n-1))
    {
      if(c<axis1+(int)pow(2,n-1))
      {
        //1사분면
        min+=time*0;
        return z(n-1,r,c,min);
      }
      else
      {
        //2사분면
        min+=time*1;
        axis1+=(int)pow(2,n-1);
        return z(n-1,r,c,min);
        
      }
    }
    else
    {
      if(c<axis1+(int)pow(2,n-1))
      {
        //3사분면
        min+=time*2;
        axis0+=(int)pow(2,n-1);
        return z(n-1,r,c,min);
      }
      else
      {
        //4사분면
        min+=time*3;
        axis0+=(int)pow(2,n-1);
        axis1+=(int)pow(2,n-1);
        return z(n-1,r,c,min);
      }
    }
  }
  return min;
}
int main()
{
  int n,r,c;
  scanf("%d%d%d",&n,&r,&c);
  n=ren(n,r>c?r:c);
  printf("%d",z(n,r,c,0));
  return 0;
}