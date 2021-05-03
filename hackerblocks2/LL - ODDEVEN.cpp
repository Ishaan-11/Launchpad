/*
Given a list, modify it such that all odd elements appear before the even ones.
The order of odd elements and even shall remain intact.

See explanation for more info.

Input Format:
The first line contains an integer N, the number of elements in the list.

The next line contains N space separated integral elements of the list.

Constraints:
1 <= T <= 1000
0 <= N <= 10^6
Output Format:
T lines of output

Sample Input:
5
1 2 3 4 5
Sample Output:
1 3 5 2 4
Explanation:
Input : 1 -> 2 -> 3 -> 4 -> 5

The order of odd elements and even does not change.
For instance 3 comes before 5 in the input, so comes in the output.

Output: 1 -> 3 -> 5 -> 2 -> 4
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
void shift(node** head,int s,int i)
{
    if(s==0 && i==1)
    {
        node*b=(*head)->next;
        (*head)->next=b->next;
        b->next=*head;
        *head=b;
        return;
    }
    if(s==0)
    {
        node*p2=find_add(*head,i-1);
        node*b=p2->next;
        p2->next=b->next;
        b->next=*head;
        *head=b;
        return;
    }
    if(i-s==1)
    {
        node*p1=find_add(*head,s-1);
        node*a=p1->next;
        node*b=a->next;
        a->next=b->next;
        b->next=a;
        p1->next=b;
        return;
    }
    node*p1=find_add(*head,s-1);
    node*a=p1->next;
    node*p2=find_add(*head,i-1);
    node*b=p2->next;
    p2->next=b->next;
    b->next=a;
    p1->next=b;
    return;
}
void odd_even(node** head,int n)
{
    int s=-1;
    for(int i=0;i<n;i++)
    {
        node*a=find_add(*head,i);
        if(a->data &2!=0)
        {
            if(s>-1)
            {
                shift(head,s,i);
                s++;
            }
            continue;
        }
        else
        {
            if(s==-1)
            {
                s=i;
            }
            continue;
        }
    }
   return;
}
int main()
{
    int n;
    cin>>n;
    node*head=0;
    createlinklist(&head,n);
    odd_even(&head,n);
    print(head);
	return 0;
}
//better method
/*
#include <iostream>
using namespace std;
struct node
{
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
void createll(node**head,int n)
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
node*oddeven(node*head)
{
    node*odd=0;
    node*even=0;
    node*oit=odd;
    node*eit=even;
    while(head)
    {
        if(head->data%2==0)
        {
            if(!even)
            {
                even=head;
                eit=even;
            }
            else
            {
                eit->next=head;
                eit=eit->next;
            }
            head=head->next;
        }
        else
        {
            if(!odd)
            {
                odd=head;
                oit=odd;
            }
            else
            {
                oit->next=head;
                oit=oit->next;
            }
            head=head->next;
        }
    }
    if(!odd)
    {
        eit->next=NULL;
        return even;
    }
    if(!even)
    {
        oit->next=NULL;
        return odd;
    }
    oit->next=even;
    eit->next=NULL;
    return odd;
}
int main()
{
    int n;
    cin>>n;
    node*head=0;
    createll(&head,n);
    //print(head);
    print(oddeven(head));
}

*/
