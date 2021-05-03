/*
Reverse a Queue using recursion.

Input Format:
Enter the size of the queue N and N more number and store in the queue.

Constraints:
None
Output Format:
Display the values of the reversed queue.

Sample Input:
3
1
2
3
Sample Output:
3 2 1 END
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
struct queue
{
    node*head;
    node*tail;
    int n;
    queue()
    {
        n=0;
        head=NULL;
        tail=NULL;
    }
    int size()
    {
        return n;
    }
    bool empty()
    {
        return head==NULL;
    }
    void enqueue(int data)
    {
        node*temp=new node(data);
        n++;
        if(empty())
        {
            head=temp;
            tail=temp;
            return;
        }
        tail->next=temp;
        tail=tail->next;
        return;
    }
    void dequeue()
    {
        if(empty())
        {
            return;
        }
        node*it=head;
        head=head->next;
        delete it;
        n--;
        return;
    }
    int top()
    {
        if(empty())
        {
            return -1;
        }
        return head->data;
    }
};
void reverse(queue &q)
{
    if(q.empty())
    {
        return;
    }
    int top=q.top();
    q.dequeue();
    reverse(q);
    q.enqueue(top);
    return;
}
int main()
{
    queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.enqueue(x);
    }
    reverse(q);
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.dequeue();
    }
    cout<<"END";
	return 0;
}
