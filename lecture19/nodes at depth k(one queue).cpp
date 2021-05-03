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
void nodesatdepthk2(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    node* mark=(root+1);
    q.push(root);
    q.push(mark);
    while(k)
    {
        node*top=q.front();
        if(top==mark)
        {
            k--;
            q.push(mark);
            q.pop();
            if(k==0)
            {
                break;
            }
            top=q.front();
        }
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
    if(!q.empty())
    {
        while(q.front()!=mark)
        {
            cout<<q.front()->data<<" ";
            q.pop();
        }
    }
    return;
}
int main()
{
    node*root=createBTree();
    //levelorder(root);
    nodesatdepthk2(root,2);
    return 0;
}
