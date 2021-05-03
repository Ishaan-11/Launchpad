#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* createlinklist()
{
    int data;
    node* head=0;
    cout<<"enter data and -1 to exit"<<endl;
    cin>>data;
    if(data!=-1)
    {
        head=new node();
        head->data=data;
        head->next=NULL;
    }
    cin>>data;
    while(data!=-1)
    {
        node* temp=new node();
        temp->data=data;
        temp->next=head;
        head=temp;
        cin>>data;
    }
    return head;
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
    return;
}
int main()
{
    node* head=createlinklist();
    print(head);
    return 0;
}
