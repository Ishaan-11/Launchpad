/*
Given a Binary Search Tree (BST) of integer values and a range [low, high], return count of nodes
where all the nodes under that node (or subtree rooted with that node) lie in the given range.

Input Format:
The first line contains a number n showing the length of the inorder array of BST
The next n line contains an integer denoting the elements of the array
The next line contains two integers denoting the value of low and high

Constraints:
2 ≤ N ≤ 10^3
Output Format:
Single integer showing the count

Sample Input:
6
10 20 33 45 55 67
1 66
Sample Output:
3
Time Limit: 5 sec
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
pair<bool,int>count(node*root,int k1,int k2)
{
    if(root==NULL)
    {
        pair<bool,int>p;
        p.first=true;
        p.second=0;
        return p;
    }
    pair<bool,int>l=count(root->left,k1,k2);
    pair<bool,int>r=count(root->right,k1,k2);
    pair<bool,int>p;
    p.second=l.second+r.second;
    if(root->data>=k1 && root->data<=k2)
    {
        p.first=true;
    }
    if(p.first & l.first & r.first)
    {
        p.first=true;
        p.second=p.second+1;
        return p;
    }
    p.first=false;
    return p;
}
int main()
{
    int a[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k1,k2;
    cin>>k1;
    cin>>k2;
    node*root=bst(a,0,n-1);
    pair<bool,int>p=count(root,k1,k2);
    cout<<p.second;
	return 0;
}
