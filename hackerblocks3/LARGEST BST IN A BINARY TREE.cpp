/*
Given a Binary Tree,
write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST)


Input Format:
The first line of input will contain an integer n.
The next line will contain n integers denoting the the preorder traversal of the BT.
 The next line will contain n more integers denoting the inorder traversal of the BT.

Constraints:
2 ≤ N ≤ 10^3
Output Format:
A single integer denoting the largest bst in a bt.

Sample Input:
4
60 65 50 70
50 65 60 70
Sample Output:
2
Time Limit: 5 sec
*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
int find(vector<int> in,int s,int e,int data)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==data)
        {
            return i;
        }
    }
    return -1;
}
node* tree(vector<int> pre,int pstart,int pend,vector<int> in,int istart,int iend)
{
    if(pstart>pend)
    {
        return NULL;
    }
    int rootdata=pre[pstart];
    int index=find(in,istart,iend,rootdata);
    int l=index-istart;
    //int r=iend-index;
    node*root=new node(rootdata);
    root->left=tree(pre,pstart+1,pstart+l,in,istart,index-1);
    root->right=tree(pre,pstart+l+1,pend,in,index+1,iend);
    return root;
}
void preorder(node* root)
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
pair<bool,pair<int,int>>check(node*root)
{
    if(root==NULL)
    {
        pair<bool,pair<int,int>>p;
        p.first=true;
        p.second.first=INT_MAX;
        p.second.second=INT_MIN;
        return p;
    }
    pair<bool,pair<int,int>>l=check(root->left);
    pair<bool,pair<int,int>>r=check(root->right);
    bool x=false;
    if(root->data>=l.second.second && root->data<r.second.first)
    {
        x=true;
    }
    pair<bool,pair<int,int>>p;
    p.first=l.first & r.first & x;
    p.second.first=min(root->data,l.second.first);
    p.second.second=max(root->data,r.second.second);
    return p;
}
int nodes(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=nodes(root->left);
    int r=nodes(root->right);
    return(l+r+1);
}
int size(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    pair<bool,pair<int,int>>p=check(root);
    if(p.first)
    {
        //cout<<nodes(root)<<endl;
        return nodes(root);
    }
    //cout<<root->data<<endl;
    int l=size(root->left);
    int r=size(root->right);
    //cout<<"L"<<l<<endl<<"R"<<r<<endl;
    return max(l,r);
}
int main()
{
    vector<int> pre;
    vector<int> in;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pre.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        in.push_back(x);
    }
    node*root=tree(pre,0,n-1,in,0,n-1);
    cout<<size(root);
   // pair<bool,pair<int,int>>p=check(root);
    //cout<<endl<<p.first<<" "<<p.second.first<<" "<<p.second.second;
    //preorder(root);
	return 0;
}
