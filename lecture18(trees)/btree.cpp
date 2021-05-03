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
node* createBtree()
{
    cout<<"enter data and -1 if empty"<<endl;
    int data;
    cin>>data;
    node* root=NULL;
    if(data!=-1)
    {
        root=new node(data);
    }
    queue<node*> q;
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
};
void preorder(node *root)
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
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
//void levelorder(node* root)
int g(node* root,int x)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=g(root->left,x);
    int right=g(root->right,x);
    if((root->data)>x)
    {
        return (left+right+1);
    }
    return (left+right);
}

int main()
{
    node* root=createBtree();
    /*cout<<"preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"inorder"<<endl;
    inorder(root);*/
    cout<<g(root,2);
    return 0;
}
// 1 2 3 4 6 5 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1
