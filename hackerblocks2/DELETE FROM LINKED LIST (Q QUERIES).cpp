/*
We are given a linked list. There are Q queries.
Each query is represented by a index x which represents the position from which the element has to be deleted.
After every query print the linked list.

Input Format:
First line contains the number of nodes in the linked list n and
queries q and then next line contains n space separated integers representing the
node values of the linked list and then q lines follow containing the indices to be deleted.

Constraints:
n < 1000
Output Format:
Output the linked list after every query. Print the node values in a single line separated by spaces.

Sample Input:
5 2
1 2 3 4 5
0
1
Sample Output:
2 3 4 5
2 4 5
Explanation:
Initially the node at index 0 is deleted and list becomes 2 3 4 5.
Then node at index 1 is deleted and the list becomes 2 4 5.

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
    cout<<endl;
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
void delete_node(node** head,int k)
{
    node* temp=*head;
    if(k==0)
    {
        *head=(*head)->next;
        delete temp;
        return;
    }
    node* a=find_add(*head,k-1);
    temp=a->next;
    a->next=temp->next;
    delete temp;
    return;
}
int main()
{
    int n,Q,q;
    cin>>n;
    cin>>Q;
    node* head=0;
    createlinklist(&head,n);
    for(int i=0;i<Q;i++)
    {
        cin>>q;
        delete_node(&head,q);
        print(head);
    }
	return 0;
}
