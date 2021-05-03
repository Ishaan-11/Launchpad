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
node* LL(node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    node*head=LL(root->left);
    node*it=head;
    node*temp=new node(root->data);
    if(head)
    {
        while(it->left)
        {
            it=it->left;
        }
        it->left=temp;
    }
    else
    {
        head=temp;
    }
    it=temp;
    it->left=LL(root->right);
    return head;
}
void printLL(node* head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->left;
    }
    cout<<"NULL";
    return;
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
    node* llroot=LL(root);
    printLL(llroot);
    return 0;
}
