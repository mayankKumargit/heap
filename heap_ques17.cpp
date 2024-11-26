/*
Maximum distinct elements after removing K elements
Given an array containing N elements. 
The task is to find the maximum number of distinct elements after removing K elements from the array.

Example 1:
Input : Arr[] = {5, 7, 5, 5, 1, 2, 2}, K = 3
Output : 4
Explanation:
Remove 2 occurrences of element 5 and 
1 occurrence of element 2.

Example 2:
Input : Arr[] = {1, 2, 3, 4, 5, 6, 7}, K = 5
Output : 2
*/
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int maxDistinctNum(int arr[], int n, int k)
{
    priority_queue<int>maxHeap;
	unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    	mp[arr[i]]++;
    for(auto it=mp.begin();it!=mp.end();it++)
    	maxHeap.push(it->second);
    for(int i=0;i<k;i++)
    {
	    int top=maxHeap.top();
    	maxHeap.pop();
        top--;
    	if(top!=0)  
            maxHeap.push(top);
    }
	return maxHeap.size();
}
int main()
{
    int *arr,n,k;
    cout<<"\nEnter the number of elements in array : ";
    cin>>n;
    arr=new int[n];
    cout<<"\nEnter the elements in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nenter the value of k : ";
    cin>>k;
    cout<<"\nmaximum distinct number after removing k distinct number is : "<<maxDistinctNum(arr,n,k);
}