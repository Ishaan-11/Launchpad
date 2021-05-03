/*
used mark approach which means used a marker and inserted that in queue which tells the level of tree

Given a binary tree. Print the level order traversal, make sure each level start at a new line.

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format
where true suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Print the level order in which the different levels are in different lines,
all the values should be in a space separated manner

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output:
10
20 30
40 50 60 73
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void btree(node** root)
{
    int data;
    char c[5];
    cin>>c;
    if(!strcmp(c,"true"))
    {
        cin>>data;
        (*root)->left=new node(data);
        btree(&((*root)->left));
    }
    cin>>c;
    if(!strcmp(c,"true"))
    {
        cin>>data;
        (*root)->right=new node(data);
        btree(&((*root)->right));
    }
    return;
}
void levelorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    node*mark=root+1;
    q.push(mark);
    while(q.front()!=mark)
    {
        node*top=q.front();
        cout<<top->data<<" ";
        q.pop();
        if(top->left)
        {
            q.push(top->left);
        }
        if(top->right)
        {
            q.push(top->right);
        }
        if(q.front()==mark)
        {
           cout<<endl;
           q.pop();
           q.push(mark);
        }
    }
}
int main()
{
    int data;
    cin>>data;
    node*root=new node(data);
    btree(&root);
    levelorder(root);
	return 0;
}
