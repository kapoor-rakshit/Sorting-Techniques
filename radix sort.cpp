#include<bits/stdc++.h>
using namespace std;
void hashing(int a[],int n,int factor)
{
    int count[10]={0};                       //initialize count of digits(0-9) to zero
    int new_a[n];
    for(int i=0;i<n;i++)
    count[(a[i]/factor)%10]++;              //hashing of each digit at ones(first iteration)||tens...place of each number

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];               //determine position of each digit by adding the previous digits occurrence count

    for(int i=n-1;i>=0;i--)
        {
            new_a[count[(a[i]/factor)%10]-1]=a[i];    //insertion of number at that position determined above
             count[(a[i]/factor)%10]--;
        }

        for(int i=0;i<n;i++)
            a[i]=new_a[i];                           //modify the array each time
}
void radixsort(int a[],int n)
{
    int gr=*max_element(a,a+n);
    int factor=1;
    while(gr>0)
    {
        hashing(a,n,factor);
        factor*=10;
        gr/=factor;
    }
}
main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    radixsort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
