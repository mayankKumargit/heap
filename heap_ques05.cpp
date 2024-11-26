/*
Merge two binary Max heaps
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void heapify(vector<int>&arr,int i,int n)
    {
        int left=2*i+1;
        int right=2*i+2;
        int index=i;
        if(left<n && arr[left]>arr[index])
            index=left;
        if(right<n && arr[right]>arr[index])
            index=right;
        if(index!=i)
        {
            swap(arr[i],arr[index]);
            heapify(arr,index,n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>res;
        for(auto i:a)
            res.push_back(i);
        for(auto i:b)
            res.push_back(i);
        int size=res.size();
        for(int i=size/2-1;i>=0;i--)
        {
            heapify(res,i,size);
        }
        return res;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

