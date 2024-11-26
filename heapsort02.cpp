// Program to implement heapsort index starting from 0
#include<iostream>
using namespace std;
void display1(int arr[],int n);
void build_heap1(int arr[],int n);
void del_root1(int arr[],int n);
void restore_down1(int arr[],int i,int n);
int main()
{
    int arr[20],i,n;
    cout<<"\n enter the number of element ina array ";
    cin>>n;
    cout<<"\n enter the element in array \n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n array element are \n";
    display1(arr,n);
    build_heap1(arr,n);
    cout<<"\n heap formed is \n";
    display1(arr,n);
    del_root1(arr,n);
    cout<<"\n array after sorting is \n";
    display1(arr,n);
    return 0;
}
void build_heap1(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        restore_down1(arr,i,n);
    }
}
void del_root1(int arr[],int size)
{
    for (int i = size- 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		restore_down1(arr, 0, i);
    }
}
void restore_down1(int arr[],int i,int size)
{
    int left=2*i+1;
    int right=2*i+2;
    int num=arr[i];
    while(right<size)
    {
        if(num>=arr[right] && num>=arr[left])
        {
            arr[i]=num;
            return;
        }
        else if(arr[left]>arr[right])
        {
            arr[i]=arr[left];
            i=left;
        }
        else
        {
            arr[i]=arr[right];
            i=right;
        }
        left=2*i+1;
        right=2*i+2;
    }
    // if number of nodes is even
    if(left==size-1 && arr[left]>num)
    {
        arr[i]=arr[left];
        i=left;
    }
    arr[i]=num;       
}
void display1(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}


