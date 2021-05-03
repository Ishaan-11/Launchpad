/*
Implement Insertion Sort in a linked list using recursion

Input Format:
Enter the size of the linked list N and take N more inputs

Output Format:
Display the elements of the sorted list in a space separated manner

Sample Input:
4
9
6
3
2
Sample Output:
2 3 6 9
Time Limit: 4 sec
*/
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
void createlinklist(node** head,int n)
{
    int data;
    cin>>data;
    *head=new node(data);
    node* it=*head;
    while(n>1)
    {
        cin>>data;
        node* temp=new node(data);
        it->next=temp;
        it=it->next;
        n--;
    }
    return;
}
void print(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
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
void shift(node**head,int i,int j)
{
    if(j==0 && i==1)
    {
        node* a=find_add(*head,i);
        (*head)->next=a->next;
        a->next=*head;
        *head=a;
        return;
    }
    if(j==0)
    {
        node* p2=find_add(*head,i-1);
        node* a=p2->next;
        p2->next=a->next;
        a->next=*head;
        *head=a;
        return;
    }
    if(i-j==1)
    {
        node*a=find_add(*head,i);
        node* p1=find_add(*head,j-1);
        node* b=p1->next;
        b->next=a->next;
        p1->next=a;
        a->next=b;
        return;
    }
    node* p1=find_add(*head,j-1);
    node* p2=find_add(*head,i-1);
    node* a=p2->next;
    node* b=p1->next;
    p1->next=a;
    p2->next=a->next;
    a->next=b;
    return;
}
void insertion_sort(node** head,int i,int j)
{
    int n=length(*head);
    if(head==NULL)
    {
        return;
    }
    if(i==n)
    {
        return;
    }
    if(j==i+1)
    {
        insertion_sort(head,i+1,0);
        return;
    }
    node* a=find_add(*head,i);
    node* b=find_add(*head,j);
    if(b->data > a->data)
    {
        shift(head,i,j);
        insertion_sort(head,i+1,0);
        return;
    }
    insertion_sort(head,i,j+1);
    return;
}
int main()
{
    int n;
    cin>>n;
    node* head=0;
    createlinklist(&head,n);
    insertion_sort(&head,0,0);
    print(head);
	return 0;
}
