/*
Given a binary tree , print the nodes in left to right manner as visible from above the tree


Input Format:
Level order input for the binary tree will be given.

Constraints:
No of nodes in the tree can be less than or equal to 10^7
Output Format:
A single line containing space separated integers representing the top view of the tree

Sample Input:
1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
Sample Output:
4 2 1 3

check for
1 3 2 -1 -1 4 -1 5 -1 6 -1 -1 -1
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
node* BTree()
{
    int data;
    cin>>data;
    queue<node*>q;
    node*root;
    if(data!=-1)
    {
        root=new node(data);
        q.push(root);
    }
    while(!q.empty())
    {
        node*top=q.front();
        q.pop();
        //left node
        cin>>data;
        if(data!=-1)
        {
            node*left=new node(data);
            top->left=left;
            q.push(left);
        }
        //right node
        cin>>data;
        if(data!=-1)
        {
            node*right=new node(data);
            top->right=right;
            q.push(right);
        }
    }
    return root;
}
void mark(node*root,int m,int i)
{
    static int level=i;
    if(root==NULL)
    {
        return;
    }
    if(level== i && m==i)
    {
        level++;
        cout<<root->data<<" ";
    }
    mark(root->left,m-1,i);
    mark(root->right,m+1,i);
    return;
}
pair<int,int> index(node*root,int m)
{
    if(root==NULL)
    {
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>l=index(root->left,m-1);
    pair<int,int>r=index(root->right,m+1);
    pair<int,int>p;
    p.first=m;
    p.second=m;
    if(min(l.first,r.first)<m)
    {
        p.first=min(l.first,r.first);
    }
    if(max(r.second,l.second)>m)
    {
        p.second=max(r.second,l.second);
    }
    return p;
}
int main()
{
    node*root=BTree();
    pair<int,int>p=index(root,0);
    //cout<<p.first<<" "<<p.second;
    for(int i=p.first;i<=p.second;i++)
    {
        mark(root,0,i);
       // cout<<endl;
    }
	return 0;
}
//by using map
/*
#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct node
{
    int data;
    int hd;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* createBTree()
{
    node*root=0;
    int data;
    queue<node*>q;
    cin>>data;
    if(data!=-1)
    {
        root=new node(data);
        q.push(root);
    }
    while(!q.empty())
    {
        node*top=q.front();
        q.pop();
        cin>>data;
        if(data!=-1)
        {
            top->left=new node(data);
            q.push(top->left);
        }
        cin>>data;
        if(data!=-1)
        {
            top->right=new node(data);
            q.push(top->right);
        }
    }
    return root;
}
void topview(node*root)
{
    if(root==NULL)
    {
        return;
    }
    int hd=0;
    queue<node*>q;
    map<int,int>m;
    q.push(root);
    root->hd=hd;
    while(!q.empty())
    {
        node*top=q.front();
        q.pop();
        if(m.find(top->hd)==m.end())
        {
            m[top->hd]=top->data;
        }
        if(top->left)
        {
            top->left->hd=top->hd-1;
            q.push(top->left);
        }
        if(top->right)
        {
            top->right->hd=top->hd+1;
            q.push(top->right);
        }
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";
    }
    return;
}
int main()
{
    node*root=createBTree();
    topview(root);
	return 0;
}
*/
