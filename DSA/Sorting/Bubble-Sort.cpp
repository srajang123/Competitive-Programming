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
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;            }
        }
    }
    cout<<"The sorted Array is:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}