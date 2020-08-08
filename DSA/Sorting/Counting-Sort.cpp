#include<bits/stdc++.h>
using namespace std;
#define MAXR 1000
/*
    Time Complexity: O(n+k)
    Space Complexity: O(n+k)
    Stable Sort: No
*/

int main()
{
    int a[100],i,j,k,n,count[MAXR+1],out[100];
    cout<<"Enter Elements of Array:\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        count[a[i]]++;
    for(i=1;i<=MAXR;i++)
        count[i]+=count[i-1];
    for(i=0;i<n;i++)
    {
        a[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    cout<<"The sorted Array is:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}