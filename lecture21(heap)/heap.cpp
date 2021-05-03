#include<iostream>
#include<vector>
using namespace std;
class heap
{
private:
    vector<int> v;
    void heapify(int i)
    {
        int minindex=i;
        int left=2*i;
        int right=2*i+1;
        if(left < v.size() && v[minindex] > v[left])
        {
            minindex=left;
        }
        if( right < v.size() && v[minindex] > v[right])
        {
            minindex=right;
        }
        if(minindex!=i)
        {
            swap(v[minindex],v[i]);
            heapify(minindex);
        }
        return;
    }
public:
    heap()
    {
        v.push_back(-1);
    }
    bool empty()
    {
        return v.size()==1;
    }
    void add(int data)
    {
        v.push_back(data);
        int index=v.size()-1;
        while(index > 1 && v[index]<v[index/2])
        {
            swap(v[index],v[index/2]);
            index=index/2;
        }
        return;
    }
    int min()
    {
        if(empty())
        {
            return -1;
        }
        return v[1];
    }
    int removemin()
    {
        int min=v[1];
        v[1]=v[v.size()-1];
        v.pop_back();
        heapify(1);
        return min;
    }
    void print()
    {
        for(int i=1;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
};
int main()
{
    heap h;
    h.add(5);h.add(8);h.add(4);
    h.add(7);h.add(1);
    h.print();
    //<<h.min()<<endl;
    cout<<h.removemin()<<endl;
    h.print();
    cout<<h.removemin()<<endl;
    h.print();
    return 0;
}
