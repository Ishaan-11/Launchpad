#include<iostream>
#include<queue>
#include<map>
using namespace std;
map<int,vector<int>> m;
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
node* createBtree()
{
    cout<<"enter data and -1 if empty"<<endl;
    int data;
    cin>>data;
    node* root=NULL;
    if(data!=-1)
    {
        root=new node(data);
    }
    queue<node*> q;
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
};
void insert(node *root,int value)
{
    if(root==NULL)
    {
        return;
    }
    m[value].push_back(root->data);
    insert(root->left,value-1);
    insert(root->right,value+1);
    return;
}
void print()
{
    map<int,vector<int>>:: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    node* root=createBtree();
    insert(root,0);
    print();
    return 0;
}
