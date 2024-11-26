// Program to implement heap index starting from 0 using recursion
#include<iostream>
using namespace std;
class maxHeap
{
    int capacity,*heap;
    int size;
    public:
        maxHeap(int cap);
        void insert(int key);
        void restoreUp(int i);
        void restoreDown(int i);
        void increaseKey(int key,int index);
        void print();
        int del();
        void buildHeap();
};
maxHeap::maxHeap(int cap)
{
    capacity=cap;
    size=0;
    heap=new int[cap];
}
void maxHeap::insert(int key)
{
    if(size>=capacity)
    {
        cout<<"\nNo space available";
        return;
    }
    int i=size;
    heap[size]=key;
    size++;
    restoreUp(size-1);
}
void maxHeap::restoreUp(int i)
{
    if(i>0)
    {
        int parent=(i-1)/2;
        if(heap[i]>heap[parent])
        {
            swap(heap[i],heap[parent]);
            restoreUp(parent);
        }
    }
}
void maxHeap::restoreDown(int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int index=i;
    if(left<size && heap[left]>heap[index])
        index=left;
    if(right<size && heap[right]>heap[index])
        index=right;
    if(index!=i)
    {
        swap(heap[index],heap[i]);
        restoreDown(index);
    }
}
int maxHeap::del()
{
    if(size==0)
    {
        cout<<"\nheap is empty\n";
        return -1;
    }
    int max=heap[0];
    heap[0]=heap[size-1];
    size--;
    restoreDown(0);
    return max;
}
void maxHeap::print()
{
    if(size==0)
    {
        cout<<"\nheap is empty";
        return;
    }
    for(int i=0;i<size;i++)
    {
        cout<<heap[i]<<" ";
    }
}
void maxHeap::increaseKey(int index,int key)
{
    if(index>=size || heap[index]>key)
    {
        cout<<"\nnot possible for given case";
        return;
    }
    heap[index]=key;
    restoreUp(index);
}
void maxHeap::buildHeap()
{
    int n;
    cout<<"\nEnter the number of elements in heap : ";
    cin>>n;
    size=n;
    cout<<"\nEnter the element in array\n";
    for(int i=0;i<n;i++)
        cin>>heap[i];
    for(int i=size/2-1;i>=0;i--) // of i=(size-2)/2
    {
        restoreDown(i);
    }
}
int main()
{
    int n;
    cout<<"\nEnter the size of the heap : ";
    cin>>n;
    maxHeap heap(n);
    int choice;
    while(1)
    {
        cout<<"\n1. Insert\n2. build heap \n3. Display items of the heap\n4. delete item\n"
                "5.increase key\n 6. Quit\n";
        cout<<"\nenter your choice :  ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                    int item;
                    cout<<"\nenter the items to be insert  ";
                    cin>>item;
                    heap.insert(item);
                    break;
            case 2:
                    heap.buildHeap();
                    break;
            case 3:
                    cout<<"\nitems present in heap is : ";
                    heap.print();
                    break;
            case 4:
                    cout<<"\ndeleted item is : "<<heap.del();
                    break;
            case 5:
                    int index,key;
                    cout<<"\nEnter the index and key for increase key : ";
                    cin>>index>>key;
                    heap.increaseKey(index,key);
                    break;
            case 6:
                    exit(1);
            case 7:
                    cout<<"\nwrong choice\n";
        }
    }
}