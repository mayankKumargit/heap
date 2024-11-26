// Program of heap sort using iteration and starting from index 1
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
    int l_child=2*i;
    int r_child=l_child+1;
    int num=arr[i];
    while(r_child<=size)
    {
        if(num>=arr[l_child] && num>arr[r_child])
        {
            arr[i]=num;
            return;
        }
        else if(arr[l_child]>arr[r_child])
        {
            arr[i]=arr[l_child];
            i=l_child;
        }
        else
        {
            arr[i]=arr[r_child];
            i=r_child;
        }
        l_child=2*i;
        r_child=l_child+1;
    }
    if(l_child==size && num<=arr[l_child])
    {
        arr[i]=arr[l_child];
        i=l_child;
    }
    arr[i]=num;
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