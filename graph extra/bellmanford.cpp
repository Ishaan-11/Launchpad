#include <iostream>
#include<climits>
using namespace std;
struct Edge
{
    int src,dest,weight;
};
class Graph
{
    public:
    int v,e;
    Edge* edge;
    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        edge=new Edge[e];
    }
    void addedge(int u,int v,int w,int count)
    {
        edge[count].src=u;
        edge[count].dest=v;
        edge[count].weight=w;
        return;
    }
    void Bellmanford(int src)
    {
        int dist[v];
        for(int i=0;i<v;i++)
        {
            if(i==src)
            {
                dist[i]=0;
            }
            else
            {
                dist[i]=INT_MAX;
            }
        }
        //relaxation code
        for(int i=1;i<=v-1;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src=edge[j].src;
                int dest=edge[j].dest;
                int wt=edge[j].weight;
                //relaxation code
                if(dist[src]!=INT_MAX && dist[src]+wt<dist[dest])
                {
                    dist[dest]=dist[src]+wt;
                }
            }
        }
        //check for -ve cycle
        for(int j=0;j<e;j++)
        {
            int src=edge[j].src;
            int dest=edge[j].dest;
            int wt=edge[j].weight;
            //relaxation code
            if(dist[src]!=INT_MAX && dist[src]+wt<dist[dest])
            {
                cout<<"Graph has -ve cycle"<<endl;
                return;
            }
        }
        //if no -ve cycle then print dist array
        for(int i=0;i<v;i++)
        {
            cout<<i<<" - "<<dist[i]<<endl;
        }
    }
};
int main()
{
    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w,i);
    }
    g.Bellmanford(0);
}
/*
5 8
0 1 -1
0 2 4
1 2 3
3 2 5
4 3 -3
1 4 2
1 3 2
3 1 1
*/
