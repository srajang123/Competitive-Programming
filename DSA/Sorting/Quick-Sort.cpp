#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    Stable Sort: Yes
*/

int Partition(int a[],int l,int r)
{
    int i,j,k;
    i=l;
    j=r;
    int pivot=a[l];
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        {
            k=a[i];
            a[i]=a[j];
            a[j]=k;
        }
    }while(i<j);
    k=a[l];
    a[l]=a[j];
    a[j]=k;
    return j;
}

void QuickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int k=Partition(a,l,r);
        QuickSort(a,l,k-1);
        QuickSort(a,k+1,r);
    }
}

int main()
{
    int a[100],i,j,k,n;
    cout<<"Enter Elements of Array:\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    QuickSort(a,0,n-1);
    cout<<"The sorted Array is:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}