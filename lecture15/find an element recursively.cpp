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
void find(node* head,int k)
{
    if(k==0)
    {
        cout<<"the value is "<<head->data<<endl;
        return;
    }
    find(head->next,k-1);
    return;
}
node* find0(node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(k==0)
    {
        return head;
    }
    return find0(head->next,k-1);
}
node* find1(node* head,int x)
{
    if(head==NULL)
    {
        return 0;
    }
    if(head->data==x)
    {
        return head;
    }
    return find1(head->next,x);
}
node* find2(node* head,int x)//finding from last
{
    if(head==NULL)
    {
        return 0;
    }
    node* temp=find2(head->next,x);
    if(temp)
    {
        return temp;
    }
    if(head->data==x)
    {
        return head;
    }
    return NULL;
}
int main()
{
    node* head=0;
    int k;
    int x;
    createll(&head);
    print(head);
    cout<<"enter the position"<<endl;
    cin>>k;
    find(head,k);
    cout<<find0(head,k)->data<<endl;
    cout<<"enter a value"<<endl;
    cin>>x;
    if(find1(head,x))
    {
        cout<<find1(head,x)->data;
    }
    else
    {
        cout<<"not found";
    }
    /*if(find2(head,x))
    {
        cout<<find1(head,x)->data;
    }
    else
    {
        cout<<"not found";
    }*/
    return 0;
}
