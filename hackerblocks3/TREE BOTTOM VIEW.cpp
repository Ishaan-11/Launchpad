/*
Given a binary tree , print the nodes in left to right manner as visible from below the tree

Input Format:
Level order input for the binary tree will be given.

Constraints:
No of nodes in the tree can be less than or equal to 10^7

Output Format:
A single line containing space separated integers representing the bottom view of the tree

Sample Input:
1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
Sample Output:
4 2 6 3
*/
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
node*createBtree()
{
    int data;
    node*root=0;
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
void bottomview(node*root)
{
    queue<node*>q;
    map<int,int>m;
    q.push(root);
    int hd=0;
    root->hd=hd;
    while(!q.empty())
    {
        node*top=q.front();
        m[top->hd]=top->data;
        q.pop();
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
}
int main()
{
    node*root=createBtree();
    //levelorder(root);
    bottomview(root);
	return 0;
}
