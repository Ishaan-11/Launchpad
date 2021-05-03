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
    node<T>* head;
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
    bool isEmpty()
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
        if(isEmpty())
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
        if(isEmpty())
        {
            return NULL;
        }
        return (head->data);
    }
};
int main()
{
    stack<char> s;
    cout<<"size "<<s.size()<<endl;
    if(s.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
    s.push('a');
    s.push('b');
    s.push('c');
    cout<<"size "<<s.size()<<endl;
    if(s.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
    cout<<"top "<<s.top()<<endl;
    s.pop();
    cout<<"top "<<s.top()<<endl;
    s.pop();
    cout<<"top "<<s.top()<<endl;
    cout<<"size "<<s.size()<<endl;
    return 0;
}
