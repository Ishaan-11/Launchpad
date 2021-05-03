/*
Reverse a Stack using Recursion.

Input Format:
First line contains an integer N (size of the stack).
Next N lines follow each containing an integer to be stored in the stack
where the last integer is at the top of the stack.

Output Format:
Output the values of the reversed stack with each value in following line.

Sample Input:
3
3
2
1
Sample Output:
3
2
1
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
struct stack
{
    private:
    node* head;
    int n;
    public:
    stack()
    {
        head=NULL;
        n=0;
    }
    int size()
    {
        return n;
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
        return (head->data);
    }
};
void AppendAtLast(stack &s,int top)
{
    if(s.empty())
    {
        s.push(top);
        return;
    }
    int t=s.top();
    s.pop();
    AppendAtLast(s,top);
    s.push(t);
    return;

}
void reverse(stack &s)
{
    if(s.empty())
    {
        return;
    }
    int top=s.top();
    s.pop();
    reverse(s);
    AppendAtLast(s,top);
    return;
}
int main()
{
    int n;
    cin>>n;
    stack s;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        s.push(p);
    }
    reverse(s);
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
	return 0;
}
