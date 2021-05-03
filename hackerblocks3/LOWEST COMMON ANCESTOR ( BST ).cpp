/*
Find LCA of two elements in a BST.

Input Format:
Enter the number of nodes N and add N more numbers to the BST,
then add the two numbers whose LCA is to be found.

Constraints:
None
Output Format:
Display the LCA value.

Sample Input:
4
5
3
2
7
7
5
Sample Output:
5
Time Limit: 4 sec
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
pair<bool,node*>LCA(node*root,int x,int y)
{
    if(root==NULL)
    {
        pair<bool,node*>p;
        p.first=false;
        p.second=NULL;
        return p;
    }
    pair<bool,node*>p;
    if(root->data==x || root->data==y)
    {
        p.first=true;
        p.second=root;
        return p;
    }
    pair<bool,node*>l=LCA(root->left,x,y);
    pair<bool,node*>r=LCA(root->right,x,y);
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
    int n;
    cin>>n;
    node*root=NULL;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        add(&root,p);
    }
    int x,y;
    cin>>x;
    cin>>y;
    pair<bool,node*>p=LCA(root,x,y);
    cout<<p.second->data;
	return 0;
}
