#include<iostream>
#include<vector>
using namespace std;
class minheap
{
    vector<int> v;
    void heapify(int i)
    {
        int minindex=i;
        int left=2*i;
        int right=2*i+1;
        if(left<v.size() && v[left]<v[minindex])
        {
            minindex=left;
        }
        if(right<v.size() && v[right]<v[minindex])
        {
            minindex=right;
        }
        if(minindex!=i)
        {
            swap(v[i],v[minindex]);
            heapify(minindex);
        }
        return;
    }
public:
    minheap()
    {
        v.push_back(-1);
    }
    int size()
    {
        return v.size();
    }
    int top()
    {
        return v[1];
    }
    void add(int data)
    {
        v.push_back(data);
        int index=v.size()-1;
        while(index>1 && v[index]<v[index/2])
        {
            swap(v[index],v[index/2]);
            index=index/2;
        }
        return;
    }
    void del()
    {
        v[1]=v[v.size()-1];
        v.pop_back();
        heapify(1);
        return;
    }
    void print()
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};
class maxheap
{
    vector<int> v;
    void heapify(int i)
    {
        int maxindex=i;
        int left=2*i;
        int right=2*i+1;
        if(left<v.size() && v[left]>v[maxindex])
        {
            maxindex=left;
        }
        if(right<v.size() && v[right]>v[maxindex])
        {
            maxindex=right;
        }
        if(maxindex!=i)
        {
            swap(v[i],v[maxindex]);
            heapify(maxindex);
        }
        return;
    }
public:
    maxheap()
    {
        v.push_back(-1);
    }
    int size()
    {
        return v.size();
    }
    int top()
    {
        return v[1];
    }
    void add(int data)
    {
        v.push_back(data);
        int index=v.size()-1;
        while(index>1 && v[index]>v[index/2])
        {
            swap(v[index],v[index/2]);
            index=index/2;
        }
        return;
    }
    void del()
    {
        v[1]=v[v.size()-1];
        v.pop_back();
        heapify(1);
        return;
    }
    void print()
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    minheap p2;
    maxheap p1;
    int n,median;
    cin>>n;
    while(n!=-1)
    {
        if(p1.size() < p2.size())
        {
            if(n<median)
            {
                p1.add(n);
            }
            else
            {
                p1.add(p2.top());
                p2.del();
                p2.add(n);
            }
            median=(p1.top()+p2.top())/2;
        }
        else if(p1.size() > p2.size())
        {
            if(n<median)
            {
                p2.add(p1.top());
                p1.del();
                p1.add(n);
            }
            else
            {
                p2.add(n);
            }
            median=(p1.top()+p2.top())/2;
        }
        else
        {
            if(n<median)
            {
                p1.add(n);
                median=p1.top();
            }
            else
            {
                p2.add(n);
                median=p2.top();
            }
        }
        cout<<"m= "<<median<<endl;
        cin>>n;
    }
   /* maxheap h;
    h.add(2);
    h.add(3);
    h.add(4);
    h.print();
    h.add(5);
    h.print();
    h.del();
    h.print();*/
    return 0;
}
