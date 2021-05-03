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
    void push(int data)
    {
        node* temp=new node(data);
        n++;
        if(isEmpty())
        {
            //temp->data=data;
            head=temp;
            return;
        }
        temp->next=head;
        head=temp;
        return;
    }
    void pop()
    {
        if(isEmpty())
        {
            return;
        }
        node* it=head;
        head=head->next;
        delete it;
        n--;
        return;
    }
    int top()
    {
        if(isEmpty())
        {
            return -1;
        }
        return (head->data);
    }
};
int main()
{
    stack s;
    cout<<"size "<<s.size()<<endl;
    if(s.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
    s.push(10);
    s.push(20);
    s.push(30);
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
