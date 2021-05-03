#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    int depth;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* createBTree()
{
    queue<node*> q;
    node* root;
    cout<<"enter root data and -1 if empty"<<endl;
    int data;
    cin>>data;
    if(data!=-1)
    {
        root=new node(data);
        q.push(root);
    }
    while(!q.empty())
    {
        node* top=q.front();
        q.pop();
        cout<<"enter left data for "<<top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1)
        {
            node*left=new node(data);
            top->left=left;
            q.push(left);
        }
        cout<<"enter right data for "<<top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1)
        {
            node*right=new node(data);
            top->right=right;
            q.push(right);
        }
    }
    return root;
}
//1 2 3 4 6 5 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1
void levelorder(node* root)
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
void populate(node* root,int d)
{
    if(root==NULL)
    {
        return;
    }
    root->depth=d;
    populate(root->left,d+1);
    populate(root->right,d+1);
    return ;
}
int main()
{
    node* root=createBTree();
    //levelorder(root);
    populate(root,0);
    cout<<root->left->right->left->depth;
    return 0;
}
