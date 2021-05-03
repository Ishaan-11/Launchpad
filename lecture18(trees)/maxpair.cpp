#include<iostream>
#include<climits>
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
    queue<node*> q;
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
node* maxpair(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    node* left=maxpair(root->left);
    node* right=maxpair(root->right);
    int grpl=INT_MIN;
    if(left)
    {
       grpl=left->data;
        //int grpl=left->data;
        if(left->left)
        {
            grpl=grpl+(left->left->data);
        }
        if(left->right)
        {
            grpl=grpl+(left->right->data);
        }
    }
    int grpr=INT_MIN;
    if(right)
    {
        grpr=right->data;
        //int grpr=right->data;
        if(right->left)
        {
            grpr=grpr+(right->left->data);
        }
        if(right->right)
        {
            grpr=grpr+(right->right->data);
        }
    }
    int grp=root->data;
    if(root->left)
    {
        grp+=(root->left->data);
    }
    if(root->right)
    {
        grp+=(root->right->data);
    }
    if(grpl>grpr)
    {
        if(grpl>grp)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
    else
    {
        if(grpr>grp)
        {
            return right;
        }
        else
        {
            return root;
        }
    }
}
int main()
{
    node*root=createBTree();
    cout<<maxpair(root)->data;
    return 0;
}
