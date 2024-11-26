/*
Median in a stream of integers (running integers)
Given that integers are read from a data stream. 
Find median of elements read so for in an efficient way. For simplicity assume, there are no duplicates. 

For example, let us consider the stream 5, 15, 1, 3 … 
After reading 1st element of stream - 5 -> median - 5
After reading 2nd element of stream - 5, 15 -> median - 10
After reading 3rd element of stream - 5, 15, 1 -> median - 5
After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
Making it clear, when the input size is odd, we take the middle element of sorted data. If the input size is even, 
we pick the average of the middle two elements in the sorted stream.
Note that output is the effective median of integers read from the stream so far. 
Such an algorithm is called an online algorithm. Any algorithm that can guarantee the output of i-elements 
after processing i-th element, is said to be online algorithm. Let us discuss three solutions to the above problem.

Method 1: Insertion Sort

If we can sort the data as it appears, we can easily locate the median element. 
Insertion Sort is one such online algorithm that sorts the data appeared so far. 
At any instance of sorting, say after sorting i-th element, the first i elements of the array are sorted. 
The insertion sort doesn’t depend on future data to sort data input till that point. In other words, 
insertion sort considers data sorted so far while inserting the next element. 
This is the key part of insertion sort that makes it an online algorithm.

However, insertion sort takes O(n2) time to sort n elements. Perhaps we can use binary search on insertion sort to 
find the location of the next element in O(log n) time. Yet, we can’t do data movement in O(log n) time. 
No matter how efficient the implementation is, it takes polynomial time in case of insertion sort.*/

/*
#include<iostream>
#include<vector>
using namespace std;
int binarySearch(int arr[],int item,int low,int high)
{
    if(low>=high)
    {
        return (item>arr[low]) ? low+1:low;
    }
    int mid=(low+high)/2;
    if(arr[mid]==item)
        return mid+1;
    else if(arr[mid]<item)
        return binarySearch(arr,item,mid+1,high);
    else
        return binarySearch(arr,item,low,mid-1);
}
vector<double>medianStream(int arr[],int n)
{
    vector<double>res;
    res.push_back(arr[0]);
    int count=1;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        int pos=binarySearch(arr,temp,0,j);
        while(j>=pos)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        count++;
        double median;
        if(count%2==1)
            median=arr[count/2];
        else
            median=(arr[(count-1)/2]+arr[count/2])/2.0;
        res.push_back(median);
    }
    return res;
}
int main()
{
    int *arr,n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    arr=new int[n];
    cout<<"\nenter the elements in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<double>res=medianStream(arr,n);
    cout<<"\nmedians are\n";
    for(auto i:res)
        cout<<i<<"   ";
    return 0;
}
*/

// using heap
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int signum(int a,int b)
{
    if(a==b)
        return 0;
    else if(a>b)
        return 1;
    else    
        return -1;
}
void getMedian(int element,int &median,priority_queue<int>&maxHeap,priority_queue <int, vector<int>, greater<int>>&minHeap)
{
    switch(signum(maxHeap.size(),minHeap.size()))
    {
        case 0: 
            if(element>median)
            {
                minHeap.push(element);
                median=minHeap.top();
            }
            else
            {
                maxHeap.push(element);
                median=maxHeap.top();
            }
            break;
        case 1:
            if(element>median)
            {
                minHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            break;
        case -1:
            if(element>median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            else
            {
                maxHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            break;
    }
}
vector<int>medianStream(int arr[],int n)
{
    vector<int>res;
    priority_queue<int>maxHeap;
    priority_queue <int, vector<int>, greater<int> > minHeap;
    int median=-1;
    for(int i=0;i<n;i++)
    {
        getMedian(arr[i],median,maxHeap,minHeap);
        res.push_back(median);
    }
    return res;
}
int main()
{
    int *arr,n;
    cout<<"\nenter the number of elements in array : ";
    cin>>n;
    arr=new int[n];
    cout<<"\nenter the elements in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>res=medianStream(arr,n);
    cout<<"\nmedians are\n";
    for(auto i:res)
        cout<<i<<"   ";
    return 0;
}