#include<bits/stdc++.h>
using namespace std;
int partion(int a[],int l,int r)
{
    int pivot=a[l];
    int wall=r+1;
    for(int i=r; i>l; i--)
    {
        if(a[i]>=pivot)
        {
            swap(a[i],a[wall-1]);
            wall--;
        }
    }
    swap(a[l],a[wall-1]);
    return wall-1;
}
void quick(int a[],int l,int r)
{
    if(l<r)
    {
        int pivot_pos=partion(a,l,r);
        quick(a,l,pivot_pos-1);
        quick(a,pivot_pos+1,r);
    }
}
main()
{
    int n;
    printf("Enter no.of elements to array\n");
    scanf("%d",&n);
    printf("Enter elements to array\n");
    int a[n+1];
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    quick(a,1,n);
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
}
