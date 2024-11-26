/*
Smallest range in K lists
Given K sorted lists of integers, KSortedArray[] of size N each. 
The task is to find the smallest range that includes at least one element from each of the K lists. 
If more than one such range's are found, return the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.

Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
*/
//{ Driver Code Starts
// T.C (n*k^2) and S.C(k)
/*
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000

class Solution{
    public:
    pair<int,int> findSmallestRange(int list[][N], int n, int k)
    {
        pair<int,int>res;
        int temp[k]={0};
        int minRange=INT_MAX;
        int minVal,maxVal;
        while(1)
        {
            int min=INT_MAX,max=INT_MIN;
            int minId;
            for(int i=0;i<k;i++)
            {
                if(list[i][temp[i]]<min)
                {
                    min=list[i][temp[i]];
                    minId=i;
                }
                if(list[i][temp[i]]>max)
                    max=list[i][temp[i]];
            }
            temp[minId]++;
            if(minRange>(max-min))
            {
                minVal=min;
                maxVal=max;
                minRange=max-min;
            }
            if(temp[minId]==n)
                break;
        }
        return {minVal,maxVal};
    }
};

//{ Driver Code Starts.
int main()
{
        int n, k;
        cout<<"\nenter n and k \n";
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";   
	return 0;
}
*/

// optimized method using min heap
// T.C(n*k*log(k)) and S.C(k)
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
        int data;
        int row;
        int col;
    
        node(int data,int i,int j)
        {
            this->data=data;
            row=i;
            col=j;
        }
};
class compare
{
    public:
        bool operator()(node *a,node *b)
        {
            return a->data>b->data;
        }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int list[][N], int n, int k)
    {
        //pair<int,int>res;
        int maxi=INT_MIN;
        priority_queue<node*,vector<node*>,compare>minHeap;
        int minVal,maxVal;
        int minRange=INT_MAX,mini;
        for(int i=0;i<k;i++)
        {
            int ele=list[i][0];
            node *temp=new node(ele,i,0);
            minHeap.push(temp);
            if(ele>maxi)
                maxi=ele;
        }
        
        while(!minHeap.empty())
        {
            node *top=minHeap.top();
            minHeap.pop();
            mini=top->data;
            if((maxi-mini)<minRange)
            {
                minRange=maxi-mini;
                minVal=mini;
                maxVal=maxi;
            }
            int col=top->col;
            int row=top->row;
            if(col+1<n)
            {
                maxi=max(list[row][col+1],maxi);
                node *temp=new node(list[row][col+1],row,col+1);
                minHeap.push(temp);
                
            }
            else
                break;
        }
        return {minVal,maxVal};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends
