/*
Find LCA(Lowest Common Ancestor) of two elements in a Binary Tree.

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format
where true suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Display the LCA value.

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
50
60
Sample Output:
10
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
void btree(node**root)
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
pair<bool,node*>LCA(node*root,int x,int y)
{
    if(root==NULL)
    {
        pair<bool,node*>p;
        p.first=false;
        p.second=NULL;
        return p;
    }
    pair<bool,node*>l=LCA(root->left,x,y);
    pair<bool,node*>r=LCA(root->right,x,y);
    pair<bool,node*>p;
    if(root->data==x || root->data==y)
    {
        p.first=true;
        p.second=root;
        return p;
    }
    if(l.first && r.first)
    {
        p.first=true;
        p.second=root;
        return p;
    }
    if(l.first)
    {
        return l;
    }
    if(r.first)
    {
        return r;
    }
    p.first=false;
    p.second=NULL;
    return p;
}
int main()
{
    int data;
    cin>>data;
    node*root=new node(data);
    btree(&root);
    int x,y;
    cin>>x;
    cin>>y;
    pair<bool,node*>p=LCA(root,x,y);
    cout<<p.second->data;
	return 0;
}
