/*
Implement Selection Sort in a linked list using iterative methods

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
void createlinklist(node**head,int n)
{
    int data;
    if(n>0)
    {
        cin>>data;
        *head=new node(data);
    }
    node*it=*head;
    while(n>1)
    {
        cin>>data;
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
        n--;
    }
    return;
}
void print(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
node* find_add(node*head,int k)
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
void swap(node** head,int i,int j)
{
    if(i==j)
    {
        return;
    }
    if(i==0 && j==1)
    {
        node*b=(*head)->next;
        (*head)->next=b->next;
        b->next=*head;
        *head=b;
        return;
    }
    if(i==0)
    {
        node*p2=find_add(*head,j-1);
        node*b=p2->next;
        p2->next=*head;
        node*temp =b->next;
        b->next=(*head)->next;
        (*head)->next=temp;
        *head=b;
        return;
    }
    if(j-i==1)
    {
        node*p1=find_add(*head,i-1);
        node*a=p1->next;
        node*b=a->next;
        p1->next=b;
        a->next=b->next;
        b->next=a;
        return;
    }
    node*p1=find_add(*head,i-1);
    node*p2=find_add(*head,j-1);
    node*a=p1->next;
    node*b=p2->next;
    p1->next=b;
    node*temp=b->next;
    b->next=a->next;
    a->next=temp;
    p2->next=a;
    return;
}
void selection_sort(node**head,int n)
{
    for(int i=0;i<n;i++)
    {
        node*a=find_add(*head,i);
        int min=a->data;
        int min_index=i;
        for(int j=i;j<n;j++)
        {
            node*b=find_add(*head,j);
            if(b->data < min)
            {
                min=b->data;
                min_index=j;
            }
        }
        swap(head,i,min_index);
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    node*head=0;
    createlinklist(&head,n);
    selection_sort(&head,n);
    print(head);
	return 0;
}
