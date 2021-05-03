/*
INTERSECTION POINT TWO LINKED LISTS
There are two linked lists. Due to some programming error,
the end node of one of the linked list got linked into the second list, forming an inverted Y shaped list.
Now it's your job to find the point(Node) at which the two linked lists are intersecting.

Input Format:
The first line of input is the size(N1) of the first linked list, followed by its content(Xi).
The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).

Constraints:
1<=N, N2<=100
0<=Xi, Yi<=100
Output Format:
A single integer denoting the intersection point of two linked lists.
If the linked lists are not intersecting at any point then print -1.

Sample Input:
5
10 20 30 40 50
4
15 25 40 50
Sample Output:
40
Explanation:
First and second linked list intersect at the node whose data value is 40.

Time Limit: 1 sec
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
node* intersection(node*head1,node* head2)
{
    int l1=length(head1);
    int l2=length(head2);
    if(l1 >= l2)
    {
        node*a=head1;
        while(a)
        {
            node* b=head2;
            while(b)
            {
                if(b->data == a->data)
                {
                    return b;
                }
                b=b->next;
            }
            a=a->next;
        }
        return NULL;
    }
    else
    {
         node*a=head2;
        while(a)
        {
            node* b=head1;
            while(b)
            {
                if(b->data == a->data)
                {
                    return b;
                }
                b=b->next;
            }
            a=a->next;
        }
        return NULL;
    }
}
int main()
{
    node* head1=0;
    node* head2=0;
    int n;
    cin>>n;
    createlinklist(&head1,n);
    cin>>n;
    createlinklist(&head2,n);
    node* head=intersection(head1,head2);
    if(head)
    {
        cout<<head->data;
    }
    else
    {
        cout<<-1;
    }
	return 0;
}
