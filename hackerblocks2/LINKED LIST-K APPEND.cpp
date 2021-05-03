/*
Append the last K elements of a linked list to the front.K can be greater than N.

Input Format:
Enter the size N, N space separated elements and number of elements that are to be appended(n).

Constraints:
None
Output Format:
Display all the elements in the list

Sample Input:
7
1 2 2 1 8 5 6
3
Sample Output:
8 5 6 1 2 2 1
Explanation:
for 1→ 2→ 3 → 4 → 5 → 6→ null and n = 2 return 5→ 6→ 1→ 2→ 3 → 4 → null
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
node* kth_element(node* head,int &k)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* a=kth_element(head->next,k);
    if(a)
    {
        return a;
    }
    if(k==0)
    {
        return head;
    }
    k--;
    return NULL;
}
void append(node** head,int k)
{
    int a=0;
    node* p1=kth_element(*head,k);
    node* last=kth_element(*head,a);
    last->next=*head;
    *head=p1->next;
    p1->next=NULL;
    return;
}
int main()
{
    node* head=0;
    int n;
    cin>>n;
    createlinklist(&head,n);
    int k;
    cin>>k;
    if(k<length(head))
    {
        append(&head,k);
        print(head);
    }
    else
    {
        append(&head,k-length(head));
        print(head);
    }
	return 0;
}
