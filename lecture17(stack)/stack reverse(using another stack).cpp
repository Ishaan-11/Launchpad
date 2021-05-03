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
        node<T>*temp=new node<T>();
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
            return ;
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
int main()
{
    stack<int> s1;
    stack<int> s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;
    int n=s1.size();
    for(int i=0;i<n-1;i++)
    {
        int top=s1.top();
            s1.pop();
        for(int j=0;j<n-1-i;j++)
        {
            int t=s1.top();
            s1.pop();
            s2.push(t);
        }
        s1.push(top);
        for(int j=0;j<n-1-i;j++)
        {
            int t1=s2.top();
            s1.push(t1);
            s2.pop();
        }
    }
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;
    return 0;
}
