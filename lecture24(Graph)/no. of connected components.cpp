#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;
    list<int> *l;
public:
    graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int u,int v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
        return;
    }
    int component(int vertex,bool visited[])
    {
        if(visited[vertex])
        {
            return 0;
        }
        visited[vertex]=true;
        list<int>::iterator it;
        for(it=l[vertex].begin();it!=l[vertex].end();it++)
        {
            component(*it,visited);
        }
        return 1;
    }
    int totalcomp()
    {
        bool visited[10]={0};
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum=sum+component(i,visited);
        }
        return sum;
    }
};
int main()
{
    graph g(8);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,5);
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(6,7);
    cout<<g.totalcomp();
    return 0;
}
