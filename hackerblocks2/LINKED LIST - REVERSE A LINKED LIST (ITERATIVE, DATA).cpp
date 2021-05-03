/*jugaad
Reverse a linked list by changing the data of its nodes in an iterative manner

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
node* reverse(node*head)
{
    node*b=head;
    node*temp=b->next;
    while(temp)
    {
        node*c=temp->next;
        temp->next=b;
        b=temp;
        temp=c;
    }
    head->next=temp;
    head=b;
    return head;
}
int main()
{
    int n;
    cin>>n;
    node* head=0;
    createlinklist(&head,n);
    print(reverse(head));
	return 0;
}
