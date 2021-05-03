#include<iostream>
#include<list>
#include<queue>
using namespace std;
class graph
{
    int V;
    list<int>* l;
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
    void bfs(int vertex)
    {
        bool visited[10]={0};
        queue<int> q;
        q.push(vertex);
        visited[vertex]=true;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            cout<<top<<" ";
            list<int>::iterator it;
            for(it=l[top].begin();it!=l[top].end();it++)
            {
                if(!visited[*it])
                {
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        return;
    }
};
int main()
{
    graph g(8);
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
    g.bfs(2);
    return 0;
}
