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
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
        cin>>data;
    }
    it->next=*head;
    return;
}
void print(node* head)
{
    node* a=head;
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->next;
        if(head==a)
        {
            break;
        }
    }
    cout<<"NULL"<<endl;
    return;
}
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
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    print(find_add(head,3));
    return 0;
}
