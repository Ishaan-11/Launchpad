/*
You are given an array of integers.
First of all , You have to form a binary search tree from given integers.
Now you have given a range.
You need to remove all nodes of the BST which are outside the given range.

Input Format:
First line contains integer t as number of test cases.
Each test case contains third lines.
First line contains an integer n which is length of the array and
second line contains n space separated integer. Third lines contains the range.

Constraints:
1 < t < 20
1< n < 50
Output Format:
For each test case you have to print preorder traversal of the original tree as well as modified tree.

Sample Input:
1
7
6 -13 14 -8 15 13 7
-10 13
Sample Output:
Preorder : 6 -13 -8 14 13 7 15
Preorder : 6 -8 13 7

*/
#include<iostream>
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
void add(node**root,int data)
{
    if(*root==NULL)
    {
        *root=new node(data);
        return;
    }
    node*it=*root;
    node*temp=new node(data);
    while(it)
    {
        if(it->data<data)
        {
            if(it->right==NULL)
            {
                it->right=temp;
                return;
            }
            it=it->right;
        }
        else
        {
            if(it->left==NULL)
            {
                it->left=temp;
                return;
            }
            it=it->left;
        }
    }
    return;
}
node* del(node*root,int r1,int r2)//postorder
{
    if(root==NULL)
    {
        return NULL;
    }
    root->left=del(root->left,r1,r2);
    root->right=del(root->right,r1,r2);
    if(root->data<r1)
    {
        node*it=root->right;
        delete root;
        return it;
    }
    if(root->data>r2)
    {
        node*it=root->left;
        delete root;
        return it;
    }
    return root;
}
void preorder(node*root)
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
int main()
{
    int t;
    cin>>t;
    for(int x=0;x<t;x++)
    {
        int n,r1,r2;
        cin>>n;
        node*root=NULL;
        for(int i=0;i<n;i++)
        {
            int e;
            cin>>e;
            add(&root,e);
        }
        cin>>r1;
        cin>>r2;
        cout<<"Preorder : ";
        preorder(root);
        cout<<endl;
        root=del(root,r1,r2);
        cout<<"Preorder : ";
        preorder(root);
        cout<<endl;
    }
	return 0;
}
/*
hint:
if root is smaller than range then its left subtree will also be out of range ,return only right subtree.
if root is greater than range then its right subtree will also be out of range ,return only left subtree.
*/
