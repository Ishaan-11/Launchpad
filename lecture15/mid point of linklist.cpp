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
node* midpoint(node* head)
{
    node* it1=head;
    node* it2=head;
    while(it2->next!=NULL && it2->next->next!=NULL)
    {
        it1=it1->next;
        it2=it2->next->next;
    }
    return it1;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    cout<<"midpoint is"<<endl;
    cout<<midpoint(head)->data;
    return 0;
}
