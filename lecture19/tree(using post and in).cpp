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
int find(vector<int> in,int s,int e,int d)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==d)
        {
            return i;
        }
    }
    return -1;
}
node* tree(vector<int>post,int pstart,int pend,vector<int> in,int istart,int iend)
{
    if(pstart>pend)
    {
        return NULL;
    }
    int rootdata=post[pend];
    int index=find(in,istart,iend,rootdata);
    int l=index-istart;
    int r=iend-index;
    node* root=new node(rootdata);
    root->left=tree(post,pstart,pstart+l-1,in,istart,index-1);
    root->right=tree(post,pstart+l,pend-1,in,index+1,iend);
    return root;
}
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
int main()
{
    vector<int>post;
    post.push_back(4);
    post.push_back(5);
    post.push_back(2);
    post.push_back(3);
    post.push_back(1);
    vector<int>in;
    in.push_back(4);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(3);
    node*root=tree(post,0,4,in,0,4);
    levelorder(root);
    return 0;
}
