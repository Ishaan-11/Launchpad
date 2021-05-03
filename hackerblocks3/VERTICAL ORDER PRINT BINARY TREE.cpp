/*
VERTICAL ORDER PRINT BINARY TREE
You will be given a Binary Tree.
Your task is to print the binary tree in Vertical Fashion.
The image below describes how we define a vertical traversal of a tree.


Input Format:
You will be given an Integer N denoting the number of levels in the corresponding tree.
On the next line you will be given (2^N)-1 integers denoting the level order input for the tree.
If at any level any node is absent then that will denoted by -1 and
every integer other than -1 shows the presence of a node at that level.

Output Format:
Print all nodes of a given column in the same line.

Image

Sample Input:
4
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
Sample Output:
4
2
1 5 6
3 8
7
9
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
    if(root==NULL)
    {
        return;
    }
    if(m==i)
    {
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
    int n;
    cin>>n;
    node*root=BTree();
    pair<int,int>p=index(root,0);
    //cout<<p.first<<" "<<p.second;
    for(int i=p.first;i<=p.second;i++)
    {
        mark(root,0,i);
        cout<<endl;
    }
	return 0;
}
//hashing
/*
#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
map<int,vector<int>>m;
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
node* create()
{
    node*root=0;
    queue<node*>q;
    int data;
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
void vertical(node*root,int d)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    vertical(root->left,d-1);
    vertical(root->right,d+1);
    return;
}
int main()
{
    int n;
    cin>>n;
    node*root=create();
    vertical(root,0);
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        for(int  i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
*/
