#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node()
    { }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void createlinklist(node** head)
{
    int data;
    cout<<"enter data and -1 to exit"<<endl;
    cin>>data;
    if(data!=-1)
    {
        *head=new node(data);
    }
    node* it=*head;
    cin>>data;
    while(data!=-1)
    {
        node* temp=new node(data);
        it->next=temp;
        it=it->next;
        cin>>data;
    }
    return;
}
void print(node* head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
    return;
}
node* reverse1(node*head,node* &tail)
{
    if(head->next==NULL)
    {
        tail=head;
        return head;
    }
    node* newhead=reverse1(head->next,tail);
    tail->next=head;
    tail=head;
    tail->next=NULL;
    return newhead;
}
pair<node*,node*> reverse2(node*head)
{
    if(head->next==NULL)
    {
        pair<node*,node*> p;
        p.first=head;
        p.second=head;
        return p;
    }
    pair<node*,node*> p=reverse2(head->next);
    p.second->next=head;
    p.second=head;
    p.second->next=NULL;
    return p;
}
int main()
{
    node* head=0;
    node*tail=0;
    createlinklist(&head);
    print(head);
    head=reverse1(head,tail);
    print(head);
    pair<node*,node*> p=reverse2(head);
    print(p.first);
    return 0;
}
