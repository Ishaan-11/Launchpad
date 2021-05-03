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
}
void insert_at_k(node** head,int data,int k)
{
    if(k==0)
    {
        node* temp=new node(data);
        temp->next=*head;
        *head=temp;
        return;
    }
    node* it=*head;
    while(--k)
    {
        it=it->next;
    }
    node* temp =new node(data);
    temp->next=it->next;
    it->next=temp;
    return;
}
void delete_at_k(node** head,int k)
{
    node* temp=*head;
    if(k==0)
    {
        *head=(*head)->next;
        delete temp;
        return;
    }
    while(--k)
    {
        temp=temp->next;
    }
    node* it=temp->next;
    temp->next=temp->next->next;
    delete it;
    return;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    cout<<"after insertion at k"<<endl;
    insert_at_k(&head,5,2);
    print(head);
    cout<<"after deletion at k"<<endl;
    delete_at_k(&head,2);
    print(head);
    return 0;
}
