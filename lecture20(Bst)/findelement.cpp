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
        this->data=data;
        left=NULL;
        right=NULL;
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
        if(it->data < data)
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
//recursive
bool find2(node*root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==data)
    {
        return true;
    }
    if(root->data < data)
    {
        return find2(root->right,data);
    }
    else
    {
        return find2(root->left,data);
    }
}
bool find(node*root,int data)
{
    while(root)
    {
        if(root->data==data)
        {
            return true;
        }
        if(root->data < data)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return false;
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
    cout<<find(root,11);
    return 0;
}
