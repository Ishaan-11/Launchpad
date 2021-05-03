#include<iostream>
#include<vector>
using namespace std;
struct stack
{
private:
    int data;
    vector<int>v;
    //int *arr;
    //int n;
public:
    //stack(int n)
    //arr=new int[n];
    //this->n=n;
    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        if(v.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void push(int data)
    {
        v.push_back(data);
        return;
    }
    void pop()
    {
        if(isEmpty())
        {
            return;
        }
        v.pop_back();
        return;
    }
    int top()
    {
        if(isEmpty())
        {
            return -1;
        }
        return v[v.size()-1];
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
