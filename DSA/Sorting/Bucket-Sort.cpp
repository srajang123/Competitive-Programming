#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
    Stable Sort: No
*/

int main()
{
    int i,j,k,n;
    float a[100];
    cout<<"Enter Elements of Array:\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<float>bucket[n];
    for(i=0;i<n;i++)
    {
        bucket[(int)(a[i]*n)].push_back(a[i]);
    }
    for(i=0;i<n;i++)
    {
        sort(bucket[i].begin(),bucket[i].end());
    }
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<bucket[i].size();j++)
            a[k++]=bucket[i][j];
    }
    cout<<"The sorted Array is:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}