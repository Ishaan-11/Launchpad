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
int find(vector<int>post,int s,int e,int d)
{
    for(int i=s;i<=e;i++)
    {
        if(post[i]==d)
        {
            return i;
        }
    }
    return -1;
}
node* tree(vector<int>pre,int prstart,int prend,vector<int> post,int postart,int poend)
{
    if(prstart>prend)
    {
        return NULL;
    }
    int rootdata=pre[prstart];
    int leftdata=pre[prstart+1];
    int index=find(post,postart,poend,leftdata);
    int l=index-postart+1;
    int r=poend-index-1;
    node*root=new node(rootdata);
    if(prstart==prend)
    {
        return root;
    }
    root->left=tree(pre,prstart+1,prstart+l,post,postart,index);
    root->right=tree(pre,prstart+l+1,prend,post,index+1,poend-1);
    return root;
}
void levelorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
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
    vector<int>pre;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(6);
    pre.push_back(7);
    pre.push_back(8);
    pre.push_back(3);
    pre.push_back(5);
    vector<int>post;
    post.push_back(4);
    post.push_back(7);
    post.push_back(8);
    post.push_back(6);
    post.push_back(2);
    post.push_back(5);
    post.push_back(3);
    post.push_back(1);
    node*root=tree(pre,0,7,post,0,7);
    levelorder(root);
    return 0;
}
