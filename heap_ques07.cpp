/*
Convert BST to Max Heap
Given a Binary Search Tree which is also a Complete Binary Tree. 
The problem is to convert a given BST into a Special Max Heap with the condition that all the values 
in the left subtree of a node should be less than all the values in the right subtree of the node. 
This condition is applied on all the nodes in the so converted Max Heap. 

Examples:  

Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  
 
Output :       7
             /   \
            3     6
          /   \  /   \
         1    2 4     5

The given BST has been transformed into aMax Heap.
All the nodes in the Max Heap satisfies the given
condition, that is, values in the left subtree of
a node should be less than the values in the right
subtree of the node.*/
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int data){  // parameterized constructor
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

Node *insert(Node *root,int data)
{
    if(root==NULL)
    {
        Node *temp=new Node(data);
        return temp;
    }    

    if(root->data<data)
        root->right=insert(root->right,data);
    else
        root->left=insert(root->left,data);

    return root;
}
Node *buildTree()
{
    int arr[20];
    int n;
    cout<<"\nEnter the number of elements to build bst : ";
    cin>>n;
    cout<<"\nEnter the element in to make bst \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    Node *root=NULL;
    for(int i=0;i<n;i++)
        root=insert(root,arr[i]);

    return root;
}
void inorder(Node *root,vector<int>&v)
{
    if(root==NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void postorder(Node *root,vector<int>&v,int &i)
{
    if(root==NULL)
        return;
    
    postorder(root->left,v,i);
    postorder(root->right,v,i);
    root->data=v[i++];
}
void convertToMaxHeapUtil(Node* root)
{
    vector<int>v;
    inorder(root,v);
    int i=0;
    postorder(root,v,i);
}    
void print(Node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    print(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node *root=NULL;
    root=buildTree();
    convertToMaxHeapUtil(root);
    print(root);
    return 0;
}