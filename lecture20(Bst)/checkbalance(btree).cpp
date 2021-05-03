#include<iostream>
#include<queue>
#include<math.h>
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
    queue<node*>q;
    node*root;
    cout<<"enter root data and -1 if empty"<<endl;
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
        cout<<"enter left data for "<<top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1)
        {
            top->left=new node(data);
            q.push(top->left);
        }
        cout<<"enter right data for "<<top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1)
        {
            top->right=new node(data);
            q.push(top->right);
        }
    }
    return root;
}
void levelorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*top=q.front();
        q.pop();
        cout<<top->data<<" ";
        if(top->left)
        {
            q.push(top->left);
        }
        if(top->right)
        {
            q.push(top->right);
        }
    }
    return;
}
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return (max(l,r)+1);
}
bool checkbal1(node*root)
{
    if(root==NULL)
    {
        return true;
    }
    bool l=checkbal1(root->left);
    bool r=checkbal1(root->right);
    int hl=height(root->left);
    int hr=height(root->right);
    bool x=false;
    if(abs(hl-hr)<=1)
    {
        x=true;
    }
    return (x & l & r);
}
pair<bool,int> checkbal2(node*root)
{
    if(root==NULL)
    {
        pair<bool,int>p;
        p.first=true;
        p.second=0;
        return p;
    }
    pair<bool,int>l=checkbal2(root->left);
    pair<bool,int>r=checkbal2(root->right);
    bool x=false;
    if(abs(l.second-r.second)<=1)
    {
        x=true;
    }
    pair<bool,int> p;
    p.first=(x & l.first & r.first);
    p.second=max(l.second,r.second)+1;
    return p;
}
int main()
{
    node*root=BTree();
    levelorder(root);
    cout<<endl<<checkbal1(root);
    pair<bool,int>p=checkbal2(root);
    cout<<endl<<p.first<<" "<<p.second;
    return 0;
}
//5 3 6 1 4 -1 10 -1 -1 -1 -1 -1 -1
//5 3 6 1 1 -1 -1 1 -1 -1 -1 1 -1 -1
