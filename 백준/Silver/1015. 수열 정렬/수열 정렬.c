#include<stdio.h>

void merge(int *a, int p, int q, int r)
{
    int tmp[r-p+1];
    int i=p, j=q+1, t=0;
    while(i<=q && j<=r)
    {
        if(a[i]<=a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }
    while(i<=q) tmp[t++]=a[i++];
    while(j<=r) tmp[t++]=a[j++];
    i=p;
    t=0;
    while(i<=r) a[i++]=tmp[t++];
}

void merge_sort(int *a, int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    int n,table[1001];
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    merge_sort(b,0,n-1);
    for(int i=n-1; i>=0; i--) table[b[i]]=i;
    for(int i=0; i<n; i++) printf("%d ",table[a[i]]++);
    return 0;
}