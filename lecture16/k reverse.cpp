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
void createlinklist(node**head)
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
node*find_add(node*head,int k)
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
node* kreverse(node* head,node* &tail)
{
    if(head==tail)
    {
        tail=head->next;
        return head;
    }
    node* newhead=kreverse(head->next,tail);
    head->next->next=head;
    head->next=tail;
    return newhead;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    int k;
    cout<<"enter value of k"<<endl;
    cin>>k;
    node* tail=find_add(head,k);
    head=kreverse(head,tail);
    print(head);
    //cout<<find_add(head,2)->data;
    return 0;
}

