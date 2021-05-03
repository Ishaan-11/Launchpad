#include<iostream>
#include<list>
#include<stack>
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
        return ;
    }
    void toposort(int v,bool visited[],stack<int> &s)
    {
        if(visited[v])
        {
            return;
        }
        visited[v]=true;
        list<int>::iterator it;
        for(it=l[v].begin();it!=l[v].end();it++)
        {
            toposort(*it,visited,s);
        }
        s.push(v);
        return;
    }
    void forall()
    {
        stack<int> s;
        bool visited[100]={0};
        for(int i=1;i<V;i++)
        {
            toposort(i,visited,s);
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        return;
    }
};
int main()
{
    graph g(8);
    g.addedge(1,7,0);
    g.addedge(2,1,0);
    g.addedge(2,4,0);
    g.addedge(3,1,0);
    g.addedge(3,6,0);
    g.addedge(4,5,0);
    g.addedge(5,6,0);
    g.forall();
    return 0;
}
