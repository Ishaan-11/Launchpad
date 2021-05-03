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
node* createlinklist()
{
    int data;
    node* head=0;
    cout<<"enter data and -1 to exit"<<endl;
    cin>>data;
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
        it=it->next;
        cin>>data;
    }
    return head;
}
void createlinklist1(node** head)
{
    int data;
    cout<<"enter data and -1 to exit"<<endl;
    cin>>data;
    if(data!=-1)
    {
        *head=new node();
        (*head)->data=data;
        (*head)->next=NULL;
    }
    node* it=*head;
    cin>>data;
    while(data!=-1)
    {
        node* temp=new node();
        temp->data=data;
        temp->next=NULL;
        it->next=temp;
        it=it->next;
        cin>>data;
    }
    return;
}
void createlinklist2(node* &head)
{
    int data;
    cout<<"enter data and -1 to exit"<<endl;
    cin>>data;
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
    cout<<"NULL";
}
//accessing next element for a given node
node* nextelement(node* element)
{
    if(element->next=NULL)
    {
        return NULL;
    }
    return element->next;
}
int main()
{
    node* head=createlinklist();
    //node* head=0;
    //createlinklist1(&head);
    //createlinklist2(head);
    print(head);
    return 0;
}
