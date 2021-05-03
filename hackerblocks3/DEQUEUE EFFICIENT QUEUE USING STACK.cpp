/*
Implement a Queue using two stacks Make it Dequeue efficient.


Input Format:
Enter the size of the queue N add 0 - N-1 numbers in the queue

Output Format:
Display the numbers in the order they are dequeued and in a space separated manner

Sample Input:
5
Sample Output:
0 1 2 3 4
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
struct stack
{
    private:
    int n;
    node*head;
    public:
    stack()
    {
        n=0;
        head=NULL;
    }
    bool empty()
    {
        return n==0;
    }
    void push(int data)
    {
        node*temp=new node(data);
        n++;
        if(empty())
        {
            head=temp;
            return;
        }
        temp->next=head;
        head=temp;
        return;
    }
    void pop()
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
class queue
{
    stack s1;
    stack s2;
    public:
    bool isempty()
    {
        return s1.empty();
    }
    void enqueue(int data)
    {
        if(isempty())
        {
            s1.push(data);
            return;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }
    void dequeue()
    {
        if(isempty())
        {
            return;
        }
        s1.pop();
        return;
    }
    int Top()
    {
        if(isempty())
        {
            return -1;
        }
        return s1.top();
    }
};
int main()
{
    int n;
    cin>>n;
    queue q;
    for(int i=0;i<n;i++)
    {
        q.enqueue(i);
    }
    while(!q.isempty())
    {
        cout<<q.Top()<<" ";
        q.dequeue();
    }
	return 0;
}
