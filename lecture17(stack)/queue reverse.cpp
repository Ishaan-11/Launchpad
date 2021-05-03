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
    node<T>* head;
    node<T>* tail;
    int n;
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
void reverse(queue<T> &q)
{
    if(q.isempty())
    {
        return;
    }
    T top=q.top();
    q.dequeue();
    reverse(q);
    q.enqueue(top);
    return;
}
int main()
{
    queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.top()<<endl;
    cout<<q.size()<<endl;
    reverse(q);
    cout<<q.top()<<endl;
    cout<<q.size()<<endl;
    return 0;
}
