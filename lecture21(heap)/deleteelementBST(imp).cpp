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
    node*it=*root;
    node*temp=new node(data);
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
node* deleteelement(node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        //0 child
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        //1child
        if(root->left && !root->right)
        {
            node*it=root->left;
            delete root;
            return it;
        }
        if(!root->left && root->right)
        {
            node*it=root->right;
            delete root;
            return it;
        }
        //2child
        if(root->left && root->right)
        {
            node* parent=root;
            node*it=root->right;
            while(it->left)
            {
                parent=it;
                it=it->left;
            }
            it->left=root->left;
            if(parent!=root)
            {
                parent->left=it->right;
                it->right=root->right;
            }
            delete root;
            return it;
        }
    }
    if(root->data < data)
    {
        root->right=deleteelement(root->right,data);
    }
    else
    {
        root->left=deleteelement(root->left,data);
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
int main()
{
    node*root=NULL;
    addelement(&root,2);
    addelement(&root,1);
    addelement(&root,7);
    addelement(&root,5);
    addelement(&root,20);
    addelement(&root,3);
    addelement(&root,4);
    addelement(&root,10);
    addelement(&root,22);
    addelement(&root,21);
    addelement(&root,23);
    addelement(&root,15);
    addelement(&root,13);
    addelement(&root,12);
    addelement(&root,14);
    addelement(&root,16);
    levelorder(root);
    cout<<endl;
    deleteelement(root,7);
    levelorder(root);
    cout<<endl;
    return 0;
}

