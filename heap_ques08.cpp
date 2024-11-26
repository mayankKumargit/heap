/*
K-th Largest Sum Contiguous Subarray
You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.

Example 1:

Input:
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.
 

Example 2:
Input:
N = 4
K = 3
Arr = {2,6,4,1}
Output:
11
Explanation:
The different subarray sums we can get from the array
are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.
*/
// using brute force
// S.C(n^2) and T.C(n^2log(n^2))

/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int kthLargest(int arr[],int n,int k)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            v.push_back(sum);
        }
    }
    int m=v.size();
    sort(v.begin(),v.end());
    return v[m-k];
}
int main()
{
    int n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    int *arr=new int[n];
    cout<<"\nenter the elements in array \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"\nenter the k value : ";
    cin>>k;
    cout<<"\n kth largest subarray sum is : "<<kthLargest(arr,n,k);
}
*/

// Efficient solution
// S.C(k) and T.C(n^2log(k))
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int kthLargest(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(pq.size()<k)
            {
                pq.push(sum);
            }
            else
            {
                if(sum>pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main()
{
    int n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    int *arr=new int[n];
    cout<<"\nenter the elements in array \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"\nenter the k value : ";
    cin>>k;
    cout<<"\n kth largest subarray sum is : "<<kthLargest(arr,n,k);
}