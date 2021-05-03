#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;
    list<int>*l;
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
    void dfsdriver(int vertex,bool visited[])
    {
        if(visited[vertex])
        {
            return;
        }
        cout<<vertex<<" ";
        visited[vertex]=true;
        list<int>::iterator it;
        for(it=l[vertex].begin();it!=l[vertex].end();it++)
        {
            dfsdriver(*it,visited);
        }
        return;
    }
    void dfs()
    {
        bool visited[10]={0};
        for(int i=0;i<V;i++)
        {
            dfsdriver(i,visited);
        }
        return;
    }
};
int main()
{
    bool visited[10]={0};
    graph g(10);
    g.addedge(0,1);
    g.addedge(0,5);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,5);
    g.addedge(2,6);
    g.addedge(2,4);
    g.addedge(4,5);
    g.addedge(4,7);
    g.addedge(5,7);
    g.addedge(6,7);
    g.addedge(8,9);
    g.dfs();
    return 0;
}
