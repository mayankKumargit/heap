/*
k largest elements
Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  
The output elements should be printed in decreasing order.

Example 1:
Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.

Example 2:
Input:
N = 7, K = 3
Arr[] = {1, 23, 12, 9, 30, 2, 50}
Output: 50 30 23
Explanation: 3 Largest element in the
array are 50, 30 and 23.
*/
/*
#include<iostream>
#include<vector>
using namespace std;
void heapify(int arr[],int i,int size)
{
    int left=2*i+1;
    int right=2*i+2;
    int index=i;
    if(left<size && arr[left]>arr[index])
        index=left;
    if(right<size && arr[right]>arr[index])
        index=right;
    if(index!=i)
    {
        swap(arr[i],arr[index]);
        heapify(arr,index,size);
    }
}
vector<int> kLargest(int arr[], int n, int k) 
{
	for(int i=n/2-1;i>=0;i--)
    {
	    heapify(arr,i,n);
	}
    vector<int>res;
	int size=n;
    for(int i=0;i<k;i++)
	{
        res.push_back(arr[0]);
	    swap(arr[0],arr[--size]);
	    heapify(arr,0,size);
	}    
    return res;
}
int main()
{
    int *arr,n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    arr=new int[n];
    cout<<"\nenter the element in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"\nenter the number of elements to find : ";
    cin>>k;
    vector<int>res=kLargest(arr,n,k);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}*/

// Another method
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> kLargest(int arr[], int n, int k) 
{
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>res;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int *arr,n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    arr=new int[n];
    cout<<"\nenter the element in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"\nenter the number of elements to find : ";
    cin>>k;
    vector<int>res=kLargest(arr,n,k);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}