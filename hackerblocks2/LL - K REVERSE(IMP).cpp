/*
Given a head to Linked List L, write a function to reverse the list taking k elements at a time.
Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format:
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints:
0 <= N <= 10^6
0 <= K <= 10^6
Output Format:
Display the linked list after reversing every k elements

Sample Input:
9 3
9 4 1 7 8 3 2 6 5
Sample Output:
1 4 9 3 8 7 5 6 2
Explanation:
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2
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
    if(n>0)
    {
        cin>>data;
        *head=new node(data);
    }
    node* it=*head;
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
void print(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
node* reverse(node*head,int k)
{
    int count=1;
    node*b=head;
    node*temp=b->next;
    while(temp && count<k)
    {
        node*c=temp->next;
        temp->next=b;
        b=temp;
        temp=c;
        count++;
    }
    head->next=temp;
    if(temp)
    {
        head->next=reverse(temp,k);
    }
    head=b;
    return b;
}
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    node*head=0;
    createlinklist(&head,n);
    print(reverse(head,k));
	return 0;
}
