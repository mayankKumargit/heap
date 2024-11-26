/*
Adding Array Elements
Given an array Arr[] of size N and an integer K, 
you have to choose the first two minimum elements of the array and erase them, 
then insert the sum of these two elements in the array until all the elements are greater than or equal to K 
and find the number of such operations required.

Example 1:
Input:
N = 6, K = 6 
Arr[] = {1, 10, 12, 9, 2, 3}
Output: 2
Explanation: First we add (1 + 2), now the
new list becomes 3 10 12 9 3, then we add
(3 + 3), now the new list becomes 6 10 12 9,
Now all the elements in the list are greater
than 6. Hence the output is 2 i:e 2 operations
are required to do this. 
Example 2:

Input:
N = 4, K = 4
Arr[] = {5, 4, 6, 4}
Output: 0
Explanation: Every element in the given array 
is greater than or equal to K.
*/
#include<iostream>
#include<queue>
using namespace std;
int minOperations(int arr[], int n, int k) 
{
    priority_queue <int, vector<int>, greater<int> > minHeap;
    for(int i=0;i<n;i++)
    {
        minHeap.push(arr[i]);
    }
    int count=0;
    while(!minHeap.empty() && k>minHeap.top())
    {
        int a=minHeap.top();
        minHeap.pop();
        if(minHeap.empty())
            return -1;
        int b=minHeap.top();
        minHeap.pop();
        minHeap.push(a+b);
        count++;
    }
    return count;
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
    cout<<"\nminimum operations required is : "<<minOperations(arr,n,k);
}