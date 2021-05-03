/*
Merge two sorted linked lists into one.

Input Format:
Enter N and M (Size of List-1 and List-2 respectively) ,
Enter space separated N elements for list-1 and M space separated elements for list-2

Constraints:
None
Output Format:
Linked list of size N+M

Sample Input:
5
4
1 4 5 8 9
2 3 6 7
Sample Output:
1 2 3 4 5 6 7 8 9
Explanation:
Merge two sorted linked list such that the new linked list remains sorted.
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
void print(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
node* merge(node * head1,node* head2)
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
    if(head1!=NULL)
    {
        it->next=head1;
    }
    else if(head2!=NULL)
    {
        it->next=head2;
    }
    return head;
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    node* head1=0;
    node* head2=0;
    createlinklist(&head1,n);
    createlinklist(&head2,m);
    print(merge(head1,head2));
	return 0;
}
