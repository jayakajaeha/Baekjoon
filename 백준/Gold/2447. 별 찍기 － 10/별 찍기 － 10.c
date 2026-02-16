#include<stdio.h>
#include<math.h>

int cnt=0, start=0;
char starp[6561][6561];

void star(int n)
{
    if(n!=1)
    {
        for(int i=0; i<pow(9,cnt); i++)
        {
            for(int j=n/3; j<n/3*2; j++)
            {
                for(int k=n/3; k<n/3*2; k++)
                {
                    starp[j+(i/(int)pow(3,cnt))*n][k+(i%(int)pow(3,cnt))*n]=' ';
                    ///printf("<%d %d>\n",(i/(int)pow(3,cnt))*n,(i%(int)pow(3,cnt))*n);
                }
            }
        }
        cnt++;
        star(n/3);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    start=n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            starp[i][j]='*';
        }
    }
    star(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) printf("%c",starp[i][j]);
        printf("\n");
    }
    return 0;
}