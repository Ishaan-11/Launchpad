/*
Given 2 sorted linked lists , return head to the merged sorted linked list.

Input Format:
First Line contains T the number of test cases. For each test case : Line 1 : N1 the size of list 1 Line 2 : N1 elements for list 1 Line 3 : N2 the size of list 2 Line 4 : N1 elements for list 2

Constraints:
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= _Ai_ <= 10^7
Output Format:
T lines of merged output

Sample Input:
1
4
1 3 5 7
3
2 4 6
Sample Output:
1 2 3 4 5 6 7

input
2
3
123
2
12
3
567
0
//for this you have make head1 and head2 null after each test case
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
    /*
    if(n==0)
    {
        *head=NULL;
        return head;
    }*/
    if(n>0)
    {
        cin>>data;
        *head=new node(data);
    }
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
    int t,n1,n2;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        node*head1=0;
        node*head2=0;
        cin>>n1;
        createlinklist(&head1,n1);
        cin>>n2;
        createlinklist(&head2,n2);
        print(merge(head1,head2));
        cout<<endl;
    }
	return 0;
}
