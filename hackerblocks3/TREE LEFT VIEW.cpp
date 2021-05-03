/*
TREE LEFT VIEW
Given a binary tree , print its nodes from root to bottom as visible from left side of tree

Input Format:
Level order input for the binary tree will be given.

Constraints:
No of nodes in the tree can be less than or equal to 10^7
Output Format:
A single line containing space separated integers representing the left view of the tree

Sample Input:
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output:
1 2 4

check(for these trees also)
4 5 2 -1 -1 3 1 6 7 -1 -1 -1 -1 -1 -1

1 2 3 -1 4 -1 -1 -1 5 -1 6 -1 -1
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
        //left
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
void printleft(node* root,int l)
{
    static int level=0;
    if(root==NULL)
    {
        return;
    }
    if(level<l)
    {
        cout<<root->data<<" ";
        level++;
    }
    printleft(root->left,l+1);
    printleft(root->right,l+1);
    return;
}
int main()
{
    node*root=BTree();
    printleft(root,1);
	return 0;
}
