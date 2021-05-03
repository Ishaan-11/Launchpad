#include<iostream>
#include<list>
#define inf 1e9
using namespace std;
struct Graph
{
    int v;
    list<pair<int,int>>*adj;
    Graph(int v)
    {
        this->v=v;
        adj=new list<pair<int,int>>[v];
    }
    void addedge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int findminvertex(int* weight,bool* visited,int v)
    {
        int minvertex=-1;
        for(int i=0;i<v;i++)
        {
            if(!visited[i] && (minvertex==-1 || weight[i]<weight[minvertex]))
            {
                minvertex=i;
            }
        }
        return minvertex;
    }
    void prims()
    {
        bool* visited=new bool[v];
        int* weight=new int[v];
        int*parent=new int[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
            weight[i]=inf;
        }
        parent[0]=-1;
        weight[0]=0;
        for(int i=0;i<v;i++)
        {
            int minvertex=findminvertex(weight,visited,v);
            visited[minvertex]=true;
            for(auto neighbour:adj[minvertex])
            {
                if(!visited[neighbour.first])
                {
                    if(weight[neighbour.first]>neighbour.second)
                    {
                        parent[neighbour.first]=minvertex;
                        weight[neighbour.first]=neighbour.second;
                    }
                }
            }
        }
        for(int i=1;i<v;i++)
        {
            cout<<i<<"--"<<parent[i]<<" with weight "<<weight[i]<<endl;
        }
    }
};
int main()
{
    int n,e;
    cin>>n>>e;
    Graph g(n);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w);
    }
    g.prims();
    return 0;
}
/*
7 8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3
*/
