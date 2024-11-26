/*
Rearrange characters
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent 
characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no 
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.
Example 2:

Input : str = "bbbbb"
Output: 0
Explanation: Repeated characters in the string
cannot be rearranged such that there should not
be any adjacent repeated character.
*/
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
string rearrangeString(string str)
{
    unordered_map<char,int>mp;
    int n=str.length();
    for(int i=0;i<n;i++)
        mp[str[i]]++;
            
    priority_queue<pair<int,char>>pq;
    for(auto it:mp)
        pq.push(make_pair(it.second,it.first));
            
    str="";
    pair<int,char>curr=pq.top();
    pq.pop();
    str+=curr.second;
    curr.first--;
    pair<int,char>prev=curr;
    while(!pq.empty())
    {
        curr=pq.top();
        pq.pop();
        str+=curr.second;
        curr.first--;
        if(prev.first>0)
            pq.push(prev);
        prev=curr;
    }
    if(str.length()==n)
        return str;
    else
        return "-1";     
}

int main()
{
    string str;
    cout<<"\nenter string : ";
    cin>>str;
    cout<<"\nrearranged string is : "<<rearrangeString(str);

}