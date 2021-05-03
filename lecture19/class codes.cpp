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
    queue<node* > q;
    node* root;
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
        node* top=q.front();
        cout<<top->data<<" ";
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
    return;
}
bool findnode(node* root,int k)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==k)
    {
        return true;
    }
    bool left=findnode(root->left,k);
    if(left)
    {
        return left;
    }
    else
    {
        return findnode(root->right,k);
    }
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
node* mirror(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    node*temp=new node(root->data);
    temp->left=mirror(root->right);
    temp->right=mirror(root->left);
    /*node*temp=root->left;
    root->left=root->right;
    root->right=temp;*/
    return temp;
}
int find(vector<int>in,int s,int e,int d)
{
    for(int i=0;i<=e;i++)
    {
        if(in[i]==d)
        {
            return i;
        }
    }
    return -1;
}
node* tree(vector<int>post,int pstart,int pend,vector<int>in,int istart,int iend)
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
int main()
{
    /*node* root=createBTree();
    node* root1=mirror(root);
    cout<<"orignal ";
    preorder(root);
    cout<<endl;
    cout<<"mirror ";
    preorder(root1);
    //cout<<findnode(root,5);
    */
    vector<int>post;
    post.push_back(6);
    post.push_back(2);
    post.push_back(4);
    post.push_back(5);
    post.push_back(3);
    post.push_back(1);
    vector<int>in;
    in.push_back(2);
    in.push_back(6);
    in.push_back(1);
    in.push_back(4);
    in.push_back(3);
    in.push_back(5);
    node*root=tree(post,0,5,in,0,5);
    levelorder(root);
    return 0;
}
