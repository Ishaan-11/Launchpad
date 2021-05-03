#include<iostream>
using namespace std;
template<typename T>
struct node
{
    T data;
    node<T>* next;
};
template<typename T>
class queue
{
private:
    int n;
    node<T>* head;
    node<T>* tail;
public:
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
    bool isempty()
    {
        return (head==NULL);
    }
    void enqueue(T data)
    {
        node<T>* temp=new node<T>();
        temp->data=data;
        temp->next=NULL;
        n++;
        if(isempty())
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
        if(isempty())
        {
            return;
        }
        node<T>* it=head;
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
template<typename T>
struct stack
{
private:
    queue<int> q1;
    queue<int> q2;
public:
    int Ssize()
    {
        if(q1.isempty() && q2.isempty())
        {
            return 0;
        }
        if(!q1.isempty())
        {
            return(q1.size());
        }
        if(!q2.isempty())
        {
            return(q2.size());
        }
    }
    bool Sisempty()
    {
        if(q1.isempty() && q2.isempty())
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
        if(q1.isempty())
        {
            q1.enqueue(data);
            while(!q2.isempty())
            {
                T top=q2.top();
                q2.dequeue();
                q1.enqueue(top);
            }
            return;
        }
        if(q2.isempty())
        {
            q2.enqueue(data);
            while(!q1.isempty())
            {
                T top=q1.top();
                q1.dequeue();
                q2.enqueue(top);
            }
            return;
        }
    }
    void pop()
    {
        if(q1.isempty() && q2.isempty())
        {
            return;
        }
        if(!q1.isempty())
        {
            q1.dequeue();
            return;
        }
        if(!q2.isempty())
        {
            q2.dequeue();
            return;
        }
    }
    T Top()
    {
        if(q1.isempty() && q2.isempty())
        {
            return NULL;
        }
        if(!q1.isempty())
        {
            return(q1.top());
        }
        if(!q2.isempty())
        {
            return(q2.top());
        }
    }
};
int main()
{
    stack<int> s;
    cout<<s.Ssize()<<endl;
    cout<<s.Sisempty()<<endl;
    s.push(1);
    cout<<s.Top()<<endl;
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.Ssize()<<endl;
    s.push(5);
    cout<<s.Ssize()<<endl;
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    cout<<s.Top()<<endl;
    s.push(6);
    cout<<s.Top()<<endl;
    cout<<s.Ssize()<<endl;
    //return 0;
}
