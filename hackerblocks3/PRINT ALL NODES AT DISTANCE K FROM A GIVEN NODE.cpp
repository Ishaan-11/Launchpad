/*
Given a binary tree, a target node in the binary tree, and an integer value k,
print all the nodes that are at distance k from the given target node.
No parent pointers are available. Print 0 if no such node exist at distance k.

Input Format:
The first line of input will contain an integer n.
The next line will contain n integers denoting the the preorder traversal of the BT.
The next line will contain n more integers denoting the inorder traversal of the BT.
The next line will contain an integer T.
Then T lines follow you will be given 2 integers the first one denoting the value of Node and
the second one denoting the value of k.

Constraints:
2 ≤ N ≤ 10^3

Output Format:
On T lines print space separated desired output for each test case in sorted form

Sample Input:
4
60 65 50 70
50 65 60 70
2
60 1
65 2
Sample Output:
65 70
70
Time Limit: 2 sec
*/
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
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
int find(int *in,int s,int e,int d)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==d)
        {
            return i;
        }
    }
    return -1;
}
node*create(int *pre,int pstart,int pend,int*in,int istart,int iend)
{
    if(pstart>pend)
    {
        return NULL;
    }
    int rootdata=pre[pstart];
    int index=find(in,istart,iend,rootdata);
    int l=index-istart;
    node*root=new node(rootdata);
    root->left=create(pre,pstart+1,pstart+l,in,istart,index-1);
    root->right=create(pre,pstart+l+1,pend,in,index+1,iend);
    return root;
}
void print_down(node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        v.push_back(root->data);
        return;
    }
    print_down(root->left,k-1);
    print_down(root->right,k-1);
    return;
}
int printnode(node*root,int k,int target)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==target)
    {
        print_down(root,k);
        return 0;
    }
    int l=printnode(root->left,k,target);
    if(l!=-1)
    {
        if(l+1==k)
        {
            v.push_back(root->data);
        }
        else
        {
            print_down(root->right,k-l-2);
        }
        return l+1;
    }
    int r=printnode(root->right,k,target);
    if(r!=-1)
    {
        if(r+1==k)
        {
            v.push_back(root->data);
        }
        else
        {
            print_down(root->left,k-r-2);
        }
        return r+1;
    }
    return -1;
}
int main()
{
    int n;
    int pre[1000],in[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    node*root=create(pre,0,n-1,in,0,n-1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int target,k;
        cin>>target>>k;
        printnode(root,k,target);
        if(v.size()==0)
        {
            cout<<0;
        }
        else
        {
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
        }
        v.clear();
        cout<<endl;
    }
	return 0;
}
