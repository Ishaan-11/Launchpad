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
void createll(node** head)
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
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
        cin>>data;
    }
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
int length(node* head)
{
    int l=0;
    while(head!=NULL)
    {
        l++;
        head=head->next;
    }
    return l;
}
int main()
{
    node*head=0;
    createll(&head);
    print(head);
    cout<<length(head);
    return 0;
}
