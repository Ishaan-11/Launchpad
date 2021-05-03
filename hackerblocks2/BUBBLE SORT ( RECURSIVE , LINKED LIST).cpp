/*

Implement Bubble Sort in a linked list using recursion

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
void print(node*head)
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
void swap(node**head,int i,int j)
{
    if(i==0 && j==1)
    {
        node* temp =*head;
        (*head)=temp->next;
        temp->next=(*head)->next;
        (*head)->next=temp;
        return;
    }
    node* p1=find_add(*head,i-1);
    node* a=p1->next;
    node* b=a->next;
    p1->next=b;
    node* temp=b->next;
    b->next=a;
    a->next=temp;
    return;
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
void bubble_sort(node** head,int i,int j)
{
    int l=length(*head);
    if(i==l-1)
    {
        return;
    }
    if(j==l-1-i)
    {
        bubble_sort(head,i+1,0);
        return;
    }
    node* a=find_add(*head,j);
    node* b=a->next;
    if(a->data > b->data)
    {
        swap(head,j,j+1);
    }
    bubble_sort(head,i,j+1);
    return;
}
int main()
{
    node*head=0;
    int n;
    cin>>n;
    createlinklist(&head,n);
    bubble_sort(&head,0,0);
    print(head);
	return 0;
}
