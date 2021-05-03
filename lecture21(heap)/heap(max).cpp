#include<iostream>
#include<vector>
using namespace std;
class heap
{
private:
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
            swap(v[maxindex],v[i]);
            heapify(maxindex);
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
        while(index>1 && v[index/2]<v[index])
        {
            swap(v[index/2],v[index]);
            index=index/2;
        }
        return;
    }
    int max()
    {
        if(empty())
        {
            return -1;
        }
        return v[1];
    }
    int removemax()
    {
        if(empty())
        {
            return -1;
        }
        int max=v[1];
        v[1]=v[v.size()-1];
        v.pop_back();
        heapify(1);
        return max;
    }
    void print()
    {
        for(int i=1;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    heap h;
    h.add(5);h.add(8);h.add(4);
    h.add(7);h.add(1);
    h.print();
    //cout<<h.max()<<endl;
    cout<<h.removemax()<<endl;
    h.print();
    cout<<h.removemax()<<endl;
    h.print();
    return 0;
}
