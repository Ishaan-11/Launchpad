/*
Eliminate duplicates from a sorted linked list

Input Format:
First line contains T the number of test cases.

For every test case, the first line contains the number of integers N in the linked list.

The next line contains N space separated integers.

Constraints:
1 <= T <= 1000
0 <= N <= 10^7
Elements in LL <= 10^6
Output Format:
T lines each containing linked list with the unique values

Sample Input:
2
8
1 1 2 3 5 6 7 7
2
2 3
Sample Output:
1 2 3 5 6 7
2 3
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
void remove_node(node*head,int k)
{
    if(head==NULL)
    {
        return;
    }
    node*temp=find_add(head,k-1);
    node*a=temp->next;
    temp->next=a->next;
    delete a;
    return;
}
void duplicate(node*head,int n)
{
    for(int i=0;i<n;i++)
    {
        node*a=find_add(head,i);
        for(int j=i+1;j<n;j++)
        {
            node*b=find_add(head,j);
            if(a->data == b->data)
            {
                remove_node(head,j);
                j--;
                n--;
            }
        }
    }
    return;
}
int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        node*head=0;
        cin>>n;
        createlinklist(&head,n);
        duplicate(head,n);
        print(head);
        cout<<endl;
    }
	return 0;
}
