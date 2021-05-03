/*
Given a linked list with n nodes.
Find the kth element from last without computing the length of the linked list.

Input Format:
First line contains space separated integers representing the node values of the linked list.
The list ends when the input comes as '-1'. The next line contains a single integer k.

Constraints:
n < 10^5
Output Format:
Output a single line containing the node value at the kth element from last.

Sample Input:
1 2 3 4 5 6 -1
3
Sample Output:
4
Explanation:
The linked list is 1 2 3 4 5 6. -1 is not included in the list.
So the third element from the last is 4

Time Limit: 1 sec
*/
#include<iostream>
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
node* LL()
{
    node*head=NULL;
    int data;
    cin>>data;
    if(data!=-1)
    {
        head=new node(data);
    }
    node*it=head;
    cin>>data;
    while(data!=-1)
    {
        node*temp=new node(data);
        it->next=temp;
        it=it->next;
        cin>>data;
    }
    return head;
}
node* print(node*head,int &k)
{
    if(head==NULL)
    {
        return NULL;
    }
    node*a=print(head->next,k);
    if(a)
    {
        return a;
    }
    if(k==1)
    {
        return head;
    }
    k--;
    return NULL;
}
int main()
{
    node*head=LL();
    int k;
    cin>>k;
    cout<<print(head,k)->data;
	return 0;
}
