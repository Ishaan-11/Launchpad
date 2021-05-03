#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int V;
    list<int>*l;
public:
    Graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isBipartite(int src)
    {
        queue<int> q;
        q.push(src);
        int*color=new int[V];
        for(int i=0;i<V;i++)
        {
            color[i]=-1;//not visited
        }
        color[src]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v=l[u].begin();v!=l[u].end();v++)
            {
                if(color[*v]==-1)
                {
                    color[*v]=1-color[u];
                    q.push(*v);
                }
                else if(color[*v]==color[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Graph g(4);
    g.addedge(0,1);
    g.addedge(2,0);
    g.addedge(1,3);
    g.addedge(2,3);
    //g.addedge(0,3);
    if(g.isBipartite(0))
    {
        cout<<"yes it is"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}
