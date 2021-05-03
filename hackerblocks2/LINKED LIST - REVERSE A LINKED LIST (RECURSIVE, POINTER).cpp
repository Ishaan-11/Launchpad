/*
Reverse a linked list by changing the polarity of the pointers in a recursive manner

Input Format:
N -> number of nodes N spaces separated numbers -> content of linked list

Constraints:
None
Output Format:
N space separated numbers -> content of reversed linked list

Sample Input:
5
10 20 30 40 50
Sample Output:
50 40 30 20 10
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
    node*it=*head;
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
node* reverse(node* head,node* &tail)
{
    if(head->next==NULL)
    {
        tail=head;
        return head;
    }
    node* a=reverse(head->next,tail);
    tail->next=head;
    tail=head;
    tail->next=NULL;
    return a;
}
int main()
{
    int n;
    cin>>n;
    node* head=0;
    node* tail=0;
    createlinklist(&head,n);
    print(reverse(head,tail));
	return 0;
}
