#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&heap,int i,int n)
{
    //int n=heap.size();
    int l=2*i;
    int r=2*i+1;
    int lar;
    if(l<=n &&heap[l-1]>heap[i-1])
        lar=l;
    else
        lar=i;
    if(r<=n && heap[r-1]>heap[lar-1])
        lar=r;
    if(lar!=i)
    {
        int k=heap[i-1];
        heap[i-1]=heap[lar-1];
        heap[lar-1]=k;
        heapify(heap,lar,n);
    }
}
void build_heap(vector<int>&arr)
{
    int n=arr.size(),i;
    for(i=n/2;i>0;i--)
    {
        heapify(arr,i,n);
    }
}

int main()
{
    int i,j,k,n,m;
    cin>>n;
    vector<int>arr(n);
    for(i=0;i<n;i++)
        cin>>arr[i];
    int hs=n;
    build_heap(arr);
    for(i=n-1;i>0;i--)
    {
        k=arr[i];
        arr[i]=arr[0];
        arr[0]=k;
        hs--;
        heapify(arr,1,hs);
    }
    cout<<"\nSorted Array:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}