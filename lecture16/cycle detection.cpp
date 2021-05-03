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
void createlinklist(node** head)
{
    int data,a[100000],i=0;
    cin>>data;
    if(data!=-1)
    {
        *head=new node(data);
        a[i]=data;
        i++;
    }
    node*it=*head;
    cin>>data;
    while(data!=-1)
    {
        for(int k=0;k<i;k++)
        {
            if(data==a[k])
            {
                if(it->next==NULL)
                {
                    it->next=find_add(*head,k);
                }
                else
                {
                    break;
                }
            }
        }
        if(it->next==NULL)
        {
            node*temp=new node(data);
            a[i]=data;
            i++;
            it->next=temp;
            it=it->next;
        }
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
    cout<<"NULL";
    return;
}
bool detect(node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
    node* slow=head;
    node* fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast && fast->next)
    {
        if(slow==fast)
        {
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}
void detect_and_remove(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    node* slow=head;
    node* fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast && fast->next)
    {
        if(slow==fast)
        {
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==head && fast==head)
    {
        while(fast->next!=slow)
        {
            fast=fast->next;
        }
        fast->next=NULL;
        return;
    }
    if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    return;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    detect_and_remove(head);
    print(head);
    /*
    if(detect(head))
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
    */
    //print(head);
    return 0;
}
