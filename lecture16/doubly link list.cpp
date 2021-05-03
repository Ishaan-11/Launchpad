#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
    node()
    {}
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
pair<node*,node*> createlinklist()
{
    int data;
    cout<<"enter data and -1 to exit"<<endl;
    cin>>data;
    node* head=0;
    if(data!=-1)
    {
        head=new node(data);
    }
    node* it=head;
    cin>>data;
    while(data!=-1)
    {
        node* temp=new node(data);
        it->next=temp;
        temp->prev=it;
        it=it->next;
        cin>>data;
    }
    pair<node*,node*> p;
    p.first=head;
    p.second=it;
    return p;
}
void print1(node*head)//from front
{
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;;
    return;
}
void print2(node* tail)//from last
{
    while(tail)
    {
        cout<<tail->data<<"-->";
        tail=tail->prev;
    }
    cout<<"NULL"<<endl;
}
/*
node* find_add(node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(k==0)
    {
        return head;
    }
    return find_add(head->next,k-1);
}
*/
int main()
{
    pair<node*,node*> p=createlinklist();
    print1(p.first);
    print2(p.second);
    //print1(find_add(p.first,2));
    //print2(find_add(p.first,4));
    return 0;
}

