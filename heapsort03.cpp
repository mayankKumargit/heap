// Program of heap sort using recursion and starting from index 1
#include<iostream>
using namespace std;
void build_heap(int arr[],int n);
void restore_down(int arr[],int i,int n);
void del_root(int arr[],int n);
void display(int arr[],int n);
int main()
{
    int arr[20],i,n;
    arr[0]=INT_MAX;
    cout<<"\n enter the number of element ina array ";
    cin>>n;
    cout<<"\n enter the element in array \n";
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n array element are \n";
    display(arr,n);
    build_heap(arr,n);
    cout<<"\n heap formed is \n";
    display(arr,n);
    del_root(arr,n);
    cout<<"\n array after sorting is \n";
    display(arr,n);
    return 0;
}
void build_heap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        restore_down(arr,i,n);
    }
}
void restore_down(int arr[],int i,int size)
{
    int left=2*i;
    int right=2*i+1;
    int index=i;
    if(left<=size && arr[left]>arr[index])
        index=left;
    if(right<=size && arr[right]>arr[index])
        index=right;
    if(index!=i)
    {
        swap(arr[index],arr[i]);
        restore_down(arr,index,size);
    }
}
void del_root(int arr[],int size)
{
    int n=size;
    for(int i=1;i<=n;i++)
    {
        swap(arr[1],arr[size--]);
        restore_down(arr,1,size);
    }
}
void display(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<" "<<arr[i];
    }
}