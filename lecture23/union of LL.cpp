#include<iostream>
#include<unordered_set>
using namespace std;
struct node
{
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
node* LL()
{
    int data;
    cin>>data;
    node*root=NULL;
    if(data!=-1)
    {
        root=new node(data);
    }
    node*it=root;
    cin>>data;
    while(data!=-1)
    {
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
        cin>>data;
    }
    return root;
}
void print(node*root)
{
    while(root)
    {
        cout<<root->data<<"-->";
        root=root->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node*L1=LL();
    print(L1);
    node*L2=LL();
    print(L2);
    unordered_set<int> s;
    node*root=L1;
    while(root)
    {
        s.insert(root->data);
        cout<<root->data<<" ";
        root=root->next;
    }
    node*it=L2;
    while(it)
    {
        if(s.find(it->data)==s.end())
        {
            cout<<it->data<<" ";
        }
        it=it->next;
    }
}

