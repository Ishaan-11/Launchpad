#include<iostream>
using namespace std;
template<typename T>
struct node
{
    T data;
    node<T>* next;
};
template<typename T>
struct stack
{
private:
    int n;
    node<T>*head;
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
    bool isempty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(T data)
    {
        node<T>* temp=new node<T>();
        temp->data=data;
        temp->next=head;
        head=temp;
        n++;
        return;
    }
    void pop()
    {
        if(isempty())
        {
            return;
        }
        node<T>*it=head;
        head=head->next;
        delete it;
        n--;
        return;
    }
    T top()
    {
        if(isempty())
        {
            return NULL;
        }
        return (head->data);
    }
};
void AppendAtBottom(stack<int> &s,int top)
{
    if(s.isempty())
    {
        s.push(top);
        return;
    }
    int t=s.top();
    s.pop();
    AppendAtBottom(s,top);
    s.push(t);
    return;
}
void reverse(stack<int> &s)
{
    if(s.isempty())
    {
        return;
    }
    int top=s.top();
    s.pop();
    reverse(s);
    AppendAtBottom(s,top);
    return;
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    reverse(s);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    return 0;
}
