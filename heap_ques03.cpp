// Write a program to find kth smallest element in an array
// efficient and tricky method
// this method works in O(n)
#include<iostream>
#include<queue>
using namespace std;
int kthSmallest(int arr[],int k,int n)
{
    if(k>n)
        return -1;
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main()
{
    int n;
    cout<<"\nEnter the number of element in array : ";
    cin>>n;
    int *arr=new int[n];
    cout<<"\nEnter the element in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"\nenter the k value : ";
    cin>>k;
    cout<<"\nkth smallest element is : "<<kthSmallest(arr,k,n);
    return 0;
}