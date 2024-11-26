/*
Nearly sorted
Given an array of n elements, where each element is at most k away from its target position, 
you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10
Example 2:

Input:
n = 5, k = 2
arr[] = {3,1,4,2,5}
Output: 1 2 3 4 5 
*/
#include<iostream>
#include<queue> 
#include<vector>
using namespace std;
vector <int> nearlySorted(int arr[], int n, int k){
    vector<int>v;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            v.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
int main()
{
    int n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    int *arr=new int[n];
    cout<<"\nenter the elements in array such that it is sorted in k order \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"\nenter the k value : ";
    cin>>k;
    vector<int>res=nearlySorted(arr,n,k);
    for(auto i:res)
        cout<<i<<" ";
}