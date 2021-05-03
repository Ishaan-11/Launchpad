/*jugaad
Reverse a linked list by changing the data of its nodes in a recursive manner

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
node* reverse(node*head,node*&tail)
{
    if(head->next==NULL)
    {
        tail=head;
        return head;
    }
    node*a=reverse(head->next,tail);
    tail->next=head;
    tail=head;
    tail->next=NULL;
    return a;
}
int main()
{
    int n;
    cin>>n;
    node*head=0;
    node*tail=0;
    createlinklist(&head,n);
    print(reverse(head,tail));
	return 0;
}
