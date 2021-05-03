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
            node* left=new node(data);
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
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
pair<int,int> diameter(node*root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> l=diameter(root->left);
    pair<int,int> r=diameter(root->right);
    pair<int,int> p;
    p.second=max(l.second,r.second)+1;
    p.first=max((l.second+r.second+1),max(l.first,r.first));
    return p;
}
int main()
{
    node*root=createBTree();
    //levelorder(root);
    pair<int,int>p=diameter(root);
    cout<<"diameter "<<p.first<<" height "<<p.second;
    return 0;
}
