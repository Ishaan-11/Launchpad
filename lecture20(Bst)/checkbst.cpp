#include<iostream>
#include<queue>
#include<climits>
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
    queue<node*> q;
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
        if( it->data < data)
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
/*
pair<bool,pair<int,int>> check(node*root)
{
    if(root==NULL)
    {
        pair<bool,pair<int,int>>p;
        p.first=true;
        p.second.first=INT_MAX;
        p.second.second=INT_MIN;
        return p;
    }
    pair<bool,pair<int,int>>l=check(root->left);
    pair<bool,pair<int,int>>r=check(root->right);
    if(l.second.second > root->data)
    {
        l.first=false;
        return l;
    }
    if(r.second.first <= root->data)
    {
        r.first=false;
        return r;
    }
    pair<bool,pair<int,int>>p;
    p.first=true;
    p.second.first=min(root->data,l.second.first);
    p.second.second=max(root->data,r.second.second);
    return p;
}
*/
pair<bool,pair<int,int> > checkBst(node* root){
    if(root==NULL){
        pair<bool,pair<int,int> > p;
        p.first = true;
        p.second.first = INT_MAX;
        p.second.second = INT_MIN;
        return p;
    }
    pair<bool,pair<int,int> > left = checkBst(root->left);
    pair<bool,pair<int,int> > right = checkBst(root->right);
    bool x = false;
    if(root->data >= left.second.second  && root->data < right.second.first){
        x = true;
    }
    pair<bool,pair<int,int> > p;
    p.first = left.first & right.first & x;
    p.second.first = min(left.second.first,root->data);
    p.second.second = max(right.second.second,root->data);
    return p;
}
bool check2(node*root)
{
    static int x=INT_MIN;
    if(root==NULL)
    {
        return true;
    }
    bool l=check2(root->left);
    if(!l)
    {
        return false;
    }
    if(root->data > x)
    {
        x=root->data;
    }
    else
    {
        return false;
    }
    return check2(root->right);
}
int main()
{
    //node*root=createBTree();
    node*root=NULL;
    addelement(&root,5);
    addelement(&root,3);
    addelement(&root,6);
    addelement(&root,4);
    addelement(&root,1);
    addelement(&root,10);
    //levelorder(root);
    pair<bool,pair<int,int>>p=checkBst(root);
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second;
    //cout<<check2(root);
    return 0;
}
//5 3 6 1 4 -1 10 -1 -1 -1 -1 -1 -1
