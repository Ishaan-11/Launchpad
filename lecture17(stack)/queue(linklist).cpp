#include<iostream>
using namespace std;
template<typename T>
struct node
{
    node<T>* next;
    T data;
};
template<typename T>
class queue
{
private:
    node<T>* head;
    node<T>*tail;
    int n;
public:
    queue()
    {
        head=NULL;
        tail=NULL;
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
int main()
{
    queue<char> q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    cout<<q.isempty()<<endl;
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top()<<endl;
    return 0;
}
