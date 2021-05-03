#include<iostream>
using namespace std;
struct Edge
{
    int src,dest;
};
class Graph
{
public:
    int v,e;
    Edge *edge;
    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        edge=new Edge[e];
    }
    void addedge(int u,int v,int i)
    {
        edge[i].src=u;
        edge[i].dest=v;
    }
    int find_parent(int *parent,int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return find_parent(parent,parent[i]);
    }
    void Union(int *parent,int x,int y)
    {
        int xroot=find_parent(parent,x);
        int yroot=find_parent(parent,y);
        parent[xroot]=yroot;
    }
    bool iscycle()
    {
        int *parent=new int[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
        }
        for(int i=0;i<e;i++)
        {
            int x=find_parent(parent,edge[i].src);
            int y=find_parent(parent,edge[i].dest);
            if(x==y)
            {
                cout<<x<<" "<<y<<" "<<i<<endl;
                return true;
            }
            Union(parent,x,y);
        }
        return false;
    }
};
int main()
{
    int v=4,e=3;
    Graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,i);
    }
    if(g.iscycle())
    {
        cout<<"graph contains cycle"<<endl;
    }
    else
    {
        cout<<"graph doesn't contain cycle"<<endl;
    }
    return 0;
}
/*
0 1
1 2
3 2
*/
