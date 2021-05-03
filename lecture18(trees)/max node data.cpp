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
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int maxdata(node* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    int left=maxdata(root->left);
    int right=maxdata(root->right);
    int m=max(left,right);
    return max(m,root->data);
}
int main()
{
    node* root=createBTree();
    cout<<maxdata(root);
    return 0;
}
