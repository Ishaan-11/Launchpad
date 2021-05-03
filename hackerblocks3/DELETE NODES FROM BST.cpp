/*
DELETE NODES FROM BST
You are given an array A1 of integers.
You have to form first Binary Search tree and then you are provided another array A2.
You have to delete each node from the BST which is present in the array A2.
Now you have to print preorder traversal of the tree.


Input Format:
First line contains integer t as number of test cases.
Each test case It contains four lines.
First line contains integer n which represents the length of the array A1 and
next line contains n space separated integers.
Similarly third line contains integer m which represents the length of the array A2 and
next line contains m space separated integers.

Constraints:
1 < t < 100
1< n,m < 1000
Output Format:
Print the preorder of the tree

Sample Input:
1
7
5 3 2 4 7 6 8
3
2 3 5
Sample Output:
4 7 6 8
*/
#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void add(node**root,int data)
{
    if(*root==NULL)
    {
        *root=new node(data);
        return;
    }
    node*it=*root;
    node*temp=new node(data);
    while(it)
    {
        if(it->data < data)
        {
            if(it->right==NULL)
            {
                it->right=temp;
                return;
            }
            it=it->right;
        }
        else
        {
            if(it->left==NULL)
            {
                it->left=temp;
                return;
            }
            it=it->left;
        }
    }
}
void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
node* del(node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        //0child
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        //1child
        if(!root->left && root->right)
        {
            node*it=root->right;
            delete root;
            return it;
        }
        if(root->left && !root->right)
        {
            node*it=root->left;
            delete root;
            return it;
        }
        //2child
        node*parent=root;
        node*it=root->left;
        while(it->right)
        {
            parent=it;
            it=it->right;
        }
        it->right=root->right;
        if(parent!=root)
        {
            parent->right=it->left;
            it->left=root->left;
        }
        delete root;
        return it;
    }
    if(root->data < data)
    {
        root->right=del(root->right,data);
    }
    else
    {
        root->left=del(root->left,data);
    }
    return root;
}
int main()
{
    int t;
    cin>>t;
    int a[1000];
    int d[1000];
    for(int i=0;i<t;i++)
    {
        node*root=0;
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(int j=0;j<n;j++)
        {
            add(&root,a[j]);
        }
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>d[j];
        }
        for(int j=0;j<m;j++)
        {
            root=del(root,d[j]);
            //cout<<d[j];
        }
        preorder(root);
    }
	return 0;
}
