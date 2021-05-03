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
    cout<<"enter a data and -1 to exit"<<endl;
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
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void top(node** head,int data)
{
    node* temp=new node(data);
    temp->next=*head;
    *head=temp;
    return;
}
void last(node* head,int data)
{
    node* temp=new node(data);
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
    return;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    cout<<"after insertion at top"<<endl;
    top(&head,5);
    print(head);
    cout<<"after insertion at last"<<endl;
    last(head,6);
    print(head);
    return 0;
}
