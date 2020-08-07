#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    Stable Sort: Yes
*/

int main()
{
    int a[100],i,j,k,n;
    cout<<"Enter Elements of Array:\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while(j>=0 && a[j]>k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
    cout<<"The sorted Array is:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}