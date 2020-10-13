#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    Stable Sort: Yes
*/

void Merge(int a[],int l,int md,int r)
{
    int i=l,j=md+1,k=0;
    int b[r-l+1];
    while(i<=md && j<=r)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=md)    
        b[k++]=a[i++];
    while(j<=r)    
        b[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=b[i-l];
}

void MergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int md=(l+r)/2;
        MergeSort(a,l,md);
        MergeSort(a,md+1,r);
        Merge(a,l,md,r);
    }
}

int main()
{
    int a[100],i,j,k,n;
    cout<<"Enter Elements of Array:\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    MergeSort(a,0,n-1);
    cout<<"The sorted Array is:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}