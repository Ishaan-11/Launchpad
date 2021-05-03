#include<iostream>
using namespace std;
struct Edge
{
    int src,dest;
};
struct Set
{
    int parent,rank;
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
    int find_parent(Set*s,int i)
    {
        if(s[i].parent!=i)
        {
            s[i].parent=find_parent(s,s[i].parent);
        }
        return s[i].parent;
    }
    void Union(Set*s,int x,int y)
    {
        int xroot=find_parent(s,x);
        int yroot=find_parent(s,y);
        //attach smaller rank tree under root of higher rank tree
        if(s[xroot].rank < s[yroot].rank)
        {
            s[xroot].parent=yroot;
            s[yroot].rank++;
        }
        else if(s[xroot].rank > s[yroot].rank)
        {
            s[yroot].parent=xroot;
            s[xroot].rank++;
        }
        else
        {
            s[yroot].parent=xroot;
            s[xroot].rank++;
        }
    }
    bool iscycle()
    {
        Set * s=new Set[v];
        for(int i=0;i<v;i++)
        {
            s[i].parent=i;
            s[i].rank=0;
        }
        for(int i=0;i<e;i++)
        {
            int x=find_parent(s,edge[i].src);
            int y=find_parent(s,edge[i].dest);
            if(x==y)
            {
                return true;
            }
            Union(s,x,y);
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
