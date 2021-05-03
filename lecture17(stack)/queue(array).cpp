#include<iostream>
using namespace std;
template<typename T>
class queue
{
private:
    T* arr;
    int max_size;
    int cur_size;
    int front;
    int rear;
public:
    queue(int n)
    {
        max_size=n;
        cur_size=0;
        front=0;
        rear=n-1;
        arr=new T[n];
    }
    int size()
    {
        return cur_size;
    }
    bool isempty()
    {
        if(cur_size==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if(cur_size==max_size)
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
        if(isfull())
        {
            return;
        }
        rear=(rear+1)%max_size;
        arr[rear]=data;
        cur_size++;
        return;
    }
    void dequeue()
    {
        if(isempty())
        {
            return;
        }
        front=(front+1)%max_size;
        cur_size--;
        return;
    }
    T top()
    {
        if(isempty())
        {
            return NULL;
        }
        return arr[front];
    }
};
int main()
{
    queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.isfull()<<endl;
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top()<<endl;
    return 0;
}
