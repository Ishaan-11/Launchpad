/*
Given a binary search tree,
replace each nodes' data with the sum of all nodes' which are greater or equal than it.
Include the current node's data also.

Input Format:
The first line contains a number n showing the length of the inorder array of BST
The next n line contains an integer denoting the elements of the array

Constraints:
2 ≤ N ≤ 10^3
Output Format:
Print the preorder traversal of the new bst

Sample Input:
7
20 30 40 50 60 70 80
Sample Output:
260 330 350 300 150 210 80
Time Limit: 3 sec
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
node* bst(int a[1000],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int m=(s+e)/2;
    node*root=new node(a[m]);
    root->left=bst(a,s,m-1);
    root->right=bst(a,m+1,e);
    return root;
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
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            a[i]=a[i]+a[j];
        }
    }
    node*root=bst(a,0,n-1);
    preorder(root);
	return 0;
}
