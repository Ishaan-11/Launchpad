#include<iostream>
#include<vector>
using namespace std;
template<typename T>
struct stack
{
private:
    T data;
    vector<T> v;
public:
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
    void push(T data)
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
    T top()
    {
        if(isEmpty())
        {
            return NULL;
        }
        return v[v.size()-1];
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
