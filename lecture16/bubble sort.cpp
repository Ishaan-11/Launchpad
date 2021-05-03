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
void swap(node**head,int i,int j)
{
    if(i==0&&j==1)
    {
        node*temp=*head;
        *head=temp->next;
        temp->next=(*head)->next;
        (*head)->next=temp;
        return ;
    }
    if(i==0)
    {
        node* p2=find_add(*head,j-1);
        node*a=*head;
        node*b=p2->next;
        node*temp=b->next;
        b->next=a->next;
        a->next=temp;
        p2->next=*head;
        *head=b;
        return;
    }
    if(j-i==1)
    {
        node*p1=find_add(*head,i-1);
        node*a=p1->next;
        node*b=a->next;
        p1->next=b;
        node* temp=b->next;
        b->next=a;
        a->next=temp;
        return;
    }
    node*p1=find_add(*head,i-1);
    node*p2=find_add(*head,j-1);
    node*a=p1->next;
    node*b=p2->next;
    p1->next=b;
    node* temp=b->next;
    b->next=a->next;
    a->next=temp;
    p2->next=a;
    return;
}
/*my method
void swap(node** head,int i,int j)
{
    node* it1=*head;
    node* it2=*head;
    if(i==0)
    {
        if(j-i==1)
        {
            while(--j)
            {
                it2=it2->next;
            }
            node* temp=(*head);
            (*head)=(*head)->next;
            it1->next=it1->next->next;
            (*head)->next=temp;
        }
        if(j-i>1)
        {
            while(--j)
            {
                it2=it2->next;
            }
            node* temp=(*head)->next;
            (*head)->next=it2->next->next;
            it2->next->next=temp;
            node* temp1=*head;
            *head=it2->next;
            it2->next=temp1;
        }
        return;
    }
    if(j-i>1)
    {
        while(--i)
        {
            it1=it1->next;
        }
        while(--j)
        {
            it2=it2->next;
        }
        node* temp=it1->next->next;
        it1->next->next=it2->next->next;
        it2->next->next=temp;
        temp=it1->next;
        it1->next=it2->next;
        it2->next=temp;
    }
    if(j-i==1)
    {
        while(--i)
        {
            it1=it1->next;
        }
        while(--j)
        {
            it2=it2->next;
        }
        node* temp=it1->next;
        it1->next=it2->next->next;
        it2->next->next=temp;
        temp=it2->next;
        it2->next=it1->next;
        it1->next=temp;
    }
    return;
}
*/
int length(node* head)
{
    int l=0;;
    while(head)
    {
        l++;
        head=head->next;
    }
    return l;
}
void bubble_sort(node** head)
{
    int n=length(*head);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            node* a=find_add(*head,j);
            node* b=a->next;
            if(a->data > b->data)
            {
                swap(head,j,j+1);
            }
        }
    }
    return;
}
int main()
{
    node* head=0;
    createlinklist(&head);
    print(head);
    /*
    //cout<<find_add(head,2)->data;
    int i,j;
    cout<<"enter value of i"<<endl;
    cin>>i;
    cout<<"enter value of j"<<endl;
    cin>>j;
    swap(&head,i,j);
    print(head);
    //cout<<length(head);
    */
    bubble_sort(&head);
    cout<<"after bubble sort"<<endl;
    print(head);
    return 0;
}
