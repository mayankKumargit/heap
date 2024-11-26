/*
Merge k Sorted Arrays
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Example 1:
Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].

Example 2:
Input:
K = 4
arr[][]={{1,2,3,4}
         {2,2,3,4},
         {5,5,6,6},
         {7,8,9,9}
        }
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6]  [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9 ].
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;

class node{
    public:
        int data;
        int i;
        int j;
        node(int data,int row,int col)
        {
            this->data=data;
            i=row;
            j=col;
        }
};
class compare{
    public:
        bool operator()(node *a,node *b){
            return a->data > b->data;
        }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int>res;
        priority_queue<node*,vector<node*>,compare>minHeap;
        
        for(int i=0;i<k;i++)
        {
            node *temp=new node(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        while(minHeap.size()>0)
        {
            node *top=minHeap.top();
            minHeap.pop();
            int data=top->data;
            int i=top->i;
            int j=top->j;
            res.push_back(data);
            
            if(j+1<arr[i].size())
            {
                node *next=new node(arr[i][j+1],i,j+1);
                minHeap.push(next);
            }
        }
        return res;
    }
};