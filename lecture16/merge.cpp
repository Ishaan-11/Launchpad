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
        *head= new node(data);
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
node* merge(node * head1,node* head2)
{
    if(head1==NULL && head2==NULL)
    {
        return NULL;
    }
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* head=0;
    if(head1->data < head2->data)
    {
        head=head1;
        head1=head1->next;
    }
    else
    {
        head=head2;
        head2=head2->next;
    }
    node* it=head;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            it->next=head1;
            head1=head1->next;
            it=it->next;
        }
        else
        {
            it->next=head2;
            head2=head2->next;
            it=it->next;
        }
    }
    if(head1!=NULL)
    {
        it->next=head1;
        /*head1=head1->next;
        it=it->next;*/
    }
    else if(head2!=NULL)
    {
        it->next=head2;
        /*head2=head2->next;
        it=it->next;*/
    }
    return head;
}
int main()
{
    node* head1=0;
    node*head2=0;
    createlinklist(&head1);
    createlinklist(&head2);
    print(head1);
    print(head2);
    print(merge(head1,head2));
    return 0;
}
