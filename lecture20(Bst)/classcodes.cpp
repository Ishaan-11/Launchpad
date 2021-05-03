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
void addelement(node** root,int data)
{
    if(*root==NULL)
    {
        *root=new node(data);
        return;
    }
    node* temp=new node(data);
    node*it=*root;
    while(it)
    {
        if(it->data<data)
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
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
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
pair<bool,pair<int,int>> BST(node*root)
{
    if(root==NULL)
    {
        pair<bool,pair<int,int>> p;
        p.first=true;
        p.second.first=INT_MAX;
        p.second.second=INT_MIN;
        return p;
    }
    pair<bool,pair<int,int>>l=BST(root->left);
    pair<bool,pair<int,int>>r=BST(root->right);
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
    pair<bool,pair<int,int>> p;
    p.first=true;
    p.second.first=min(root->data,min(l.second.first,r.second.first));
    p.second.second=max(root->data,max(l.second.second,r.second.second));
    return p;
}
pair<bool,int> balance(node*root)
{
    if(root==NULL)
    {
        pair<bool,int>p;
        p.first=true;
        p.second=0;
        return p;
    }
    pair<bool,int>l=balance(root->left);
    pair<bool,int>r=balance(root->right);
    pair<bool,int>p;
    p.first=false;
    p.second=max(l.second,r.second)+1;
    if((l.second-r.second)>=-1 && (l.second-r.second)<=1)
    {
        p.first=true;
        return p;
    }
    p.first=(l.first & r.first & p.first);
    return p;
}

int main()
{
    node*root=NULL;
    addelement(&root,5);
    addelement(&root,3);
    addelement(&root,8);
    addelement(&root,4);
    addelement(&root,1);
    addelement(&root,10);
    addelement(&root,7);
    levelorder(root);
    cout<<endl;
    //pair<bool,int>p =balance(root);
    //cout<<p.first;
    pair<bool,pair<int,int>> p=BST(root);
    if(p.first)
    {
        cout<<"true "<<p.second.first<<" "<<p.second.second;
    }
    else
    {
        cout<<"false "<<p.second.first<<" "<<p.second.second;
    }
    return 0;
}
