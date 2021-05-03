/*
You are given an array of integers.
First of all , You have to form a binary search tree from given integers.
Now you have provided two integers k1 and k2.
You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

Input Format:
First line contains integer t as number of test cases. Each test case contains three lines.
First line contains an integer n which is length of the array and
second line contains n space separated integer.
Third line contains the value of k1 and k2.

Constraints:
1 < t < 20
1 < n < 50
Output Format:
For each test case you have to print preorder traversal of the tree first and
then print all nodes within the range k1 and k2 (inclusive).

Sample Input:
1
5
4 3 2 5 6
3 5
Sample Output:
# Preorder : 4 3 2 5 6
# Nodes within range are : 3 4 5
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
void print(node*root,int k1,int k2)
{
    if(root==NULL)
    {
        return;
    }
    print(root->left,k1,k2);
    if(root->data>=k1 && root->data<=k2)
    {
        cout<<root->data<<" ";
    }
    print(root->right,k1,k2);
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
        int k1,k2;
        cin>>k1;
        cin>>k2;
        cout<<"# Preorder : ";
        preorder(root);
        cout<<endl;
        cout<<"# Nodes within range are : ";
        print(root,k1,k2);
        cout<<endl;
    }
	return 0;
}
