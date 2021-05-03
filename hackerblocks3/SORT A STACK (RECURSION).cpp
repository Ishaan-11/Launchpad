/*
Sort a given stack using recursion.
In the recursive function use only basic functions of stack like push, pop etc.

Input Format:
First line contains the number of elements in stack , N.
Next line contains N elements in stack from bottom to top.

Constraints:
0<N<10000
Output Format:
Print the elements in sorted order from top to bottom.

Sample Input:
5
-3 14 18 -5 30
Sample Output:
30  18  14  -3  -5
Explanation:
Sort the elements in stack in descending order from top to bottom.
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
    int n;
    node* head;
    public:
    stack()
    {
        n=0;
        head=NULL;
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
        node* temp=new node(data);
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
void insert(stack &s,int top)
{
    if(s.empty() || top>=s.top())
    {
        s.push(top);
        return;
    }
    if(top<s.top())
    {
        int temp=s.top();
        s.pop();
        insert(s,top);
        s.push(temp);
        return;
    }
}
void sort(stack &s)
{
    if(s.empty())
    {
        return;
    }
    int top=s.top();
    s.pop();
    sort(s);
    insert(s,top);
    return;
}
int main()
{
    stack s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    sort(s);
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
	return 0;
}
