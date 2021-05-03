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
    node*root;
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
        node*top=q.front();
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
void NodesAtDepth_K(node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q1;
    queue<node*>q2;
    q1.push(root);
    while(k--)
    {
        if(q1.empty())
        {
            while(!q2.empty())
            {
                node*top=q2.front();
                if(top->left)
                {
                    q1.push(top->left);
                }
                if(top->right)
                {
                    q1.push(top->right);
                }
                q2.pop();
            }
        }
        else
        {
            while(!q1.empty())
            {
                node* top=q1.front();
                if(top->left)
                {
                    q2.push(top->left);
                }
                if(top->right)
                {
                    q2.push(top->right);
                }
                q1.pop();
            }
        }
    }
    while(!q1.empty())
    {
        cout<<q1.front()->data<<" ";
        q1.pop();
    }
    while(!q2.empty())
    {
        cout<<q2.front()->data<<" ";
        q2.pop();
    }
    return;
}
int main()
{
    node* root=createBTree();
    //levelorder(root);
    NodesAtDepth_K(root,2);
    return 0;
}
