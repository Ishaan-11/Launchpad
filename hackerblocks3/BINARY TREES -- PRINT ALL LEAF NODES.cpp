/*
Given a Binary Tree Print all the leaf nodes.

Input Format:
Level order input of the binary tree

Constraints:
Total no of nodes <1000
Output Format:
All leaf nodes from left to right in single line

Sample Input:
1
2 3
4 5
6 7
-1 -1
-1 -1
-1 -1
-1 -1
Sample Output:
4 5 6 7
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
    node*root;
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
        //left;
        cin>>data;
        if(data!=-1)
        {
            top->left=new node(data);
            q.push(top->left);
        }
        //right
        cin>>data;
        if(data!=-1)
        {
            top->right=new node(data);
            q.push(top->right);
        }
    }
    return root;
}
void print(node*root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    print(root->left);
    print(root->right);
    return;
}
int main()
{
    node*root=BTree();
    print(root);
	return 0;
}#include<iostream>
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
    node*root;
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
        //left;
        cin>>data;
        if(data!=-1)
        {
            top->left=new node(data);
            q.push(top->left);
        }
        //right
        cin>>data;
        if(data!=-1)
        {
            top->right=new node(data);
            q.push(top->right);
        }
    }
    return root;
}
void print(node*root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    print(root->left);
    print(root->right);
    return;
}
int main()
{
    node*root=BTree();
    print(root);
	return 0;
}
