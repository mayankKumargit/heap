// Write a program to check whether given tree is heap or not
/*
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node *right, *left;
        Node(int data)
        {
            this->data=data;
            this->right=NULL;
            this->left=NULL;
        }
};
Node* construct(Node *root)
{
    int data;
    cout<<"\nEnter data : ";
    cin>>data;
    if(data==-1)
        return NULL;

    root=new Node(data);

    cout<<"\nEnter left child of "<<data<<" (-1 for no child)";
    root->left=construct(root->left);
    cout<<"\nEnter right child of "<<data<<" (-1 for no child";
    root->right=construct(root->right);
    return root;
}
bool isCBT(Node* root)
{
    if(root==NULL)
        return true;
    queue<Node*>q;
    q.push(root);
    bool flag=false;
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            flag=true;
        }
        else
        {
            if(flag)
                return false;
            if(temp->left)
                q.push(temp->left);
            else
                q.push(NULL);
            if(temp->right)
                q.push(temp->right);
            else
                q.push(NULL);
        }
    }
    return true;
}
bool isMaxHeap(Node *tree)
{
    if(tree==NULL || (tree->left==NULL && tree->right==NULL))
        return true;
        
    bool leftSub=isMaxHeap(tree->left);
    bool rightSub=isMaxHeap(tree->right);
        
    bool check1=true,check2=true;
    if(tree->left)
    {
        if(tree->data<tree->left->data)
            check1=false;
    }
    if(tree->right)
    {
        if(tree->data<tree->right->data)
            check1=false;
    }
    return leftSub && rightSub && check1 && check2;
}
bool isHeap(Node* root) 
{
    cout<<endl<<isCBT(root);
    return isMaxHeap(root) && isCBT(root);  
}
int main()
{
    Node *root=NULL;
    root=construct(root);
    cout<<"\nis max heap : "<<isHeap(root);
    return 0;
}*/

// Another method

#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node *right, *left;
        Node(int data)
        {
            this->data=data;
            this->right=NULL;
            this->left=NULL;
        }
};
Node* construct(Node *root)
{
    int data;
    cout<<"\nEnter data : ";
    cin>>data;
    if(data==-1)
        return NULL;

    root=new Node(data);

    cout<<"\nEnter left child of "<<data<<" (-1 for no child)";
    root->left=construct(root->left);
    cout<<"\nEnter right child of "<<data<<" (-1 for no child";
    root->right=construct(root->right);
    return root;
}
int countNodes(Node *root)
{
    if(root==NULL)
        return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}
bool isCBT(Node* root,int index,int cnt)
{
    if(root==NULL)
        return true;
    if(index>=cnt)
        return false;
    else
    {
        bool left=isCBT(root->left,2*index+1,cnt);
        bool right=isCBT(root->right,2*index+2,cnt);
        return left && right;
    }

}
bool isMaxHeap(Node *tree)
{
    if(tree==NULL || (tree->left==NULL && tree->right==NULL))
        return true;
        
    bool leftSub=isMaxHeap(tree->left);
    bool rightSub=isMaxHeap(tree->right);
        
    bool check1=true,check2=true;
    if(tree->left)
    {
        if(tree->data<tree->left->data)
            check1=false;
    }
    if(tree->right)
    {
        if(tree->data<tree->right->data)
            check1=false;
    }
    return leftSub && rightSub && check1 && check2;
}
bool isHeap(Node* root) 
{
    int count=countNodes(root);
    return isMaxHeap(root) && isCBT(root,0,count);  
}
int main()
{
    Node *root=NULL;
    root=construct(root);
    cout<<"\nis max heap : "<<isHeap(root);
    return 0;
}