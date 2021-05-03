#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    node(int data)
    {
        left=NULL;
        right=NULL;
        this->data=data;
    }
};
void addelement(node**root,int data)
{
    if(*root==NULL)
    {
        *root=new node(data);
        return;
    }
    node*temp=new node(data);
    node*it=*root;
    while(it)
    {
        if(it->data <data)
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
int minelement(node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->left)
    {
        root=root->left;
    }
    return root->data;
}
int maxelement(node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->right)
    {
        root=root->right;
    }
    return root->data;
}
int main()
{
    node*root=NULL;
    addelement(&root,5);
    addelement(&root,3);
    addelement(&root,6);
    addelement(&root,4);
    addelement(&root,1);
    addelement(&root,10);
    //levelorder(root);
    cout<<minelement(root);
    cout<<endl;
    cout<<maxelement(root);
    return 0;
}
