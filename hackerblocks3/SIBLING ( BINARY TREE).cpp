/*
Given a binary tree print all nodes that don’t have a sibling

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true
suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Display all the nodes which do not have a sibling in a space separated manner

Sample Input:
50 true 12 true 18 false false false false
Sample Output:
12 18
Time Limit: 4 sec
*/
#include<iostream>
#include<cstring>
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
    node*root=new node(data);
    char c[5];
    cin>>c;
    if(!strcmp(c,"true"))
    {
        root->left=BTree();
    }
    cin>>c;
    if(!strcmp(c,"true"))
    {
        root->right=BTree();
    }
    return root;
}
void print(node* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left && !root->right)
    {
        cout<<root->left->data<<" ";
    }
    if(!root->left && root->right)
    {
        cout<<root->right->data<<" ";
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
