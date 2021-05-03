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
    queue<node*>q;
    node* root;
    cout<<"enter root data and -1 empty"<<endl;
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
    }
    return;
}
int degree(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int n=0;
    if(root->left)
    {
        n++;
    }
    if(root->right)
    {
        n++;
    }
    return n;
}
int main()
{
    node* root=createBTree();
    //levelorder(root);
    cout<<"degree "<<degree(root);
    return 0;
}
