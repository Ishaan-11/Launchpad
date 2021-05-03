/*
You are given an array of integers.
First of all , You have to form a binary search tree from given integers.
Now you have modify the BST so that all greater values in the given BST are added to every node.

Input Format:
First line contains integer t as number of test cases. Each test case contains two lines.
First line contains an integer n which is length of the array and
second line contains n space separated integer.

Constraints:
1 < t < 20
1< n < 50
Output Format:
For each test case you have to print preorder traversal of the original tree as well as modified tree.

Sample Input:
1
7
50 30 40 20 70 80 60
Sample Output:
50 30 20 40 70 60 80
260 330 350 300 150 210 80
*/
#include<iostream>
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
        if(it->data<data)
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
    return;
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
void rep(node**root,int &sum)
{
    //static int sum=0;
    if(*root==NULL)
    {
        return;
    }
    rep(&((*root)->right),sum);
    sum=sum+(*root)->data;
    (*root)->data=sum;
    rep(&((*root)->left),sum);
    return;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        node*root=NULL;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            add(&root,x);
        }
        preorder(root);
        cout<<endl;
        int sum=0;
        rep(&root,sum);
        preorder(root);
        cout<<endl;
    }
	return 0;
}
