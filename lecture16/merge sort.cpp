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
node* merge(node* head1,node* head2)
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
    if(head1)
    {
        it->next=head1;
    }
    if(head2)
    {
        it->next=head2;
    }
    return head;
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
node* merge_sort(node* head,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    if(start==end)
    {
        return head;
    }
    int mid=(start+end)/2;
    node* midnode=find_add(head,mid);
    node*head1=head;
    node*head2=midnode->next;
    midnode->next=NULL;
    head1=merge_sort(head1,start,mid);
    head2=merge_sort(head2,0,end-mid-1);//because k will start from zero to find the address when ll is divided into parts
    head=merge(head1,head2);
    return head;
}
int length(node* head)
{
    int l=0;
    while(head)
    {
        l++;
        head=head->next;
    }
    return l;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    int n=length(head);
    cout<<"after merge sort"<<endl;
    print(merge_sort(head,0,n-1));
    return 0;
}
