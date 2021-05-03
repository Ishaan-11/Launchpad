/*
You are given a sorted data of n integers.
You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

Input Format:
First line contains integer t as number of test cases.
Each test case contains following input.
First line contains integer n which represents the length of the data and
next line contains n space separated integers.

Constraints:
1 < t < 100
1< n < 1000
Output Format:
Print the preorder of the tree.

Sample Input:
1
7
1 2 3 4 5 6 7
Sample Output:
4 2 1 3 6 5 7
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
node*bst(int a[1000],int s,int e)
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
    int t;
    cin>>t;
    int a[1000];
    for(int x=0;x<t;x++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        node*root=bst(a,0,n-1);
        preorder(root);
        cout<<endl;
    }
	return 0;
}
