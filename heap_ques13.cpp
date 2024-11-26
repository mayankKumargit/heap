/*
Maximize The Array
Given two integer arrays Arr1 and Arr2 of size N. Use the greatest elements from the given arrays to create 
a new array of size N such that it consists of only unique elements and the sum of all its elements is maximum.
The created elements should contain the elements of Arr2 followed by elements of Arr1 in order of their appearance.

Note: The input array will be given in such way, that every time it is possible to make a new arr by maintaining 
the following conditions.


Example 1:

Input:
N = 5
Arr1 = {7, 4, 8, 0, 1}
Arr2 = {9, 7, 2, 3, 6}
Output: 9 7 6 4 8
Explanation: 9, 7, 6 are from 2nd array
and 4, 8 from 1st array.

Example 2:

Input: N = 4
Arr1 = {6, 7, 5, 3}
Arr2 = {5, 6, 2, 9} 
Output: 5 6 9 7 
Explanation: 5, 6, 9 are from 2nd array
and 7 from 1st array.
*/
/*
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> maximizeArray(int arr1[], int arr2[], int n) {
    vector<int>res;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr1[i]);
        s.insert(arr2[i]);
    }
    while(s.size()>n)
    {
        s.erase(*s.begin());
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(arr2[i])!=s.end())
        {
            res.push_back(arr2[i]);
            s.erase(arr2[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(arr1[i])!=s.end())
        {
            res.push_back(arr1[i]);
            s.erase(arr1[i]);
        }
    }
    return res;
}
int main()
{
    int *arr1,*arr2,n;
    cout<<"\nEnter the number of elements in array :";
    cin>>n;
    arr1=new int[n];
    arr2=new int[n];
    cout<<"\nenter the elements in array1\n";
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    cout<<"\nEnter the elements in array2\n";
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    vector<int>res=maximizeArray(arr1,arr2,n);
    cout<<"\nmaximize array elements are\n";
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}
*/

// using heap

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> maximizeArray(int arr1[], int arr2[], int n) {
    int l = n;
    vector<pair<int,int>>v;
    priority_queue<pair<int,int>>pq;
    for (int i = 0; i<n; i++)
    {
        v.push_back({arr2[i],i});
    }
    for (int i = 0; i<n; i++)
    {
        v.push_back({arr1[i],i+n});
    }
    unordered_map<int,int>um;
    for (int i = 0; i<v.size(); i++)
    {
        if (um.find(v[i].first)==um.end())
        {
            um[v[i].first] = v[i].second;
        }
    }
    for (auto it = um.begin(); it!=um.end(); it++)
    {
        pq.push({it->first, it->second});
    }
    map<int,int>m;
            
    while(l--)
    {
        auto pr = pq.top();
        pq.pop();
        m[pr.second] = pr.first;
    }
    vector<int>ans;
    for (auto x:m)
    {
        ans.push_back(x.second);
    }
    return ans;
}
int main()
{
    int *arr1,*arr2,n;
    cout<<"\nEnter the number of elements in array :";
    cin>>n;
    arr1=new int[n];
    arr2=new int[n];
    cout<<"\nenter the elements in array1\n";
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    cout<<"\nEnter the elements in array2\n";
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    vector<int>res=maximizeArray(arr1,arr2,n);
    cout<<"\nmaximize array elements are\n";
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}
