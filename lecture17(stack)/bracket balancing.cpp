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
    node<T>* head;
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
    char a[1000]="{()}";
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='[' || a[i]=='{' || a[i]=='(')
        {
            s.push(a[i]);
        }
        if(isEmpty())
        {
            cout<<"not"<<endl;
            return 0;
        }
        char top=s.top();
        if((a[i]=='}' && top=='{') || (a[i]==']' && top=='[') || (a[i]==')' && top=='('))
        {
            s.pop();
        }
        cout<<"not"<<endl;
        return 0;
    }
    if(s.isEmpty())
    {
        cout<<"balanced";
    }
    else
    {
        cout<<"not balanced";
    }
    return 0;
}


