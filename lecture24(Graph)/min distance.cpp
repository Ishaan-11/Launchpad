#include<iostream>
#include<list>
#include<queue>
#include<climits>
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
    void mindist(int vertex)
    {
        bool visited[10]={0};
        int dist[10];
        for(int i=0;i<V;i++)
        {
            dist[i]=INT_MAX;
        }
        queue<int>q;
        q.push(vertex);
        visited[vertex]=true;
        dist[vertex]=0;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            list<int>::iterator it;
            for(it=l[top].begin();it!=l[top].end();it++)
            {
                if(!visited[*it])
                {
                    dist[*it]=dist[top]+1;
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            cout<<"Min. dist of "<<i<<" is "<<dist[i]<<endl;
        }
        return;
    }
};
int main()
{
    graph g(6);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,5);
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(4,5);
    g.mindist(0);
    return 0;
}
