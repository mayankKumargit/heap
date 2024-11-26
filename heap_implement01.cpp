// program to implement heap index starting from 1 using iteration.
#include<iostream>
using namespace std;
class maxHeap
{
    int capacity,*heap;
    int size;
    public:
        maxHeap(int cap);
        void insert(int key);
        //void restoreUp();
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
    size++;
    heap[size]=key;

    // restore up
    int k=key;
    int parent=size/2;
    int i=size;
    while(heap[parent]<k && parent>=1)
    {
        heap[i]=heap[parent];
        i=parent;
        parent=i/2;
    }
    heap[i]=key;
}
void maxHeap::restoreDown(int i)
{
    int left=2*i;
    int right=2*i+1;
    int num=heap[i];
    while(right<=size)
    {
        if(num>=heap[right] && num>=heap[left])
        {
            heap[i]=num;
            return;
        }
        else if(heap[left]>heap[right])
        {
            heap[i]=heap[left];
            i=left;
        }
        else
        {
            heap[i]=heap[right];
            i=right;
        }
        left=2*i;
        right=2*i+1;
    }
    // if number of nodes is even
    if(left==size && heap[left]>num)
    {
        heap[i]=heap[left];
        i=left;
    }
    heap[i]=num;
}
int maxHeap::del()
{
    if(size==0)
    {
        cout<<"\nheap is empty\n";
        return -1;
    }
    int max=heap[1];
    heap[1]=heap[size];
    size--;
    restoreDown(1);
    return max;
}
void maxHeap::print()
{
    if(size==0)
    {
        cout<<"\nheap is empty";
        return;
    }
    for(int i=1;i<=size;i++)
    {
        cout<<heap[i]<<" ";
    }
}
void maxHeap::increaseKey(int index,int key)
{
    if(index>size || heap[index]>key)
    {
        cout<<"\nnot possible for given case";
        return;
    }
    heap[index]=key;
    
    // restore up
    int k=key ;
    int parent=index/2,i=index;
    while(heap[parent]<k && parent>=1)
    {
        heap[i]=heap[parent];
        i=parent;
        parent=i/2;
    }
    heap[i]=k;
}
void maxHeap::buildHeap()
{
    int n;
    cout<<"\nEnter the number of elements in heap : ";
    cin>>n;
    size=n;
    cout<<"\nEnter the element in array\n";
    for(int i=1;i<=n;i++)
        cin>>heap[i];
    for(int i=size/2;i>=1;i--)
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