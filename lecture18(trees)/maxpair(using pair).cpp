#include<iostream>
#include<queue>
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
node* createBTree()
{
    queue<node* > q;
    node* root;
    cout<<"enter root data and -1 if empty"<<endl;
    int data;
    cin>>data;
    if(data!=-1)
    {
        root=new node(data);
    }
    q.push(root);
    while(!q.empty())
    {
        node* top=q.front();
        q.pop();
        cout<<"enter left data for "<<top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1)
        {
            node* left=new node(data);
            top->left=left;
            q.push(left);
        }
        cout<<"enter right data for "<<top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1)
        {
            node* right=new node(data);
            top->right=right;
            q.push(right);
        }
    }
    return root;
}
pair<node*,int> max(pair<node*,int> left,pair<node*,int> right)
{
    if(left.second>right.second)
    {
        return left;
    }
    else
    {
        return right;
    }
}
pair<node*,int> maxpair(node* root)
{
    if(root==NULL)
    {
        pair<node*,int> p;
        p.second=0;
        p.first=NULL;
        return p;
    }
    pair<node*,int> left=maxpair(root->left);
    pair<node*,int> right=maxpair(root->right);
    int grp=root->data;
    if(root->left)
    {
        grp+=(root->left->data);
    }
    if(root->right)
    {
        grp+=(root->right->data);
    }
    pair<node*,int> m=max(left,right);
    if(grp>m.second)
    {
        pair<node*,int> t;
        t.first=root;
        t.second=grp;
        return t;
    }
    return m;
}
int main()
{
    node* root=createBTree();
    pair<node*,int> p=maxpair(root);
    cout<<"parent "<<p.first->data<<" sum= "<<p.second;
    return 0;
}
