#include<iostream>
#include<unordered_map>
#include<list>
#include<climits>
#include<set>
#include<vector>
using namespace std;
class graph
{
    int V;
    unordered_map<int,list<pair<int,int>>> m;
    public:
    graph(int v)
    {
        V=v;
    }
    void addEdge(int src,int dest,int weight,bool bidir=true)
    {
        m[src].push_back(make_pair(dest,weight));
        if(bidir)
        {
            m[dest].push_back(make_pair(src,weight));
        }
    }
    void shortestpath(int src)
    {
        vector<int> dist;
        for(int i=0;i<V;i++)
        {
            dist.push_back(INT_MAX);
        }
        dist[src]=0;
        set<pair<int,int>> s;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            set<pair<int,int>>::iterator setit=s.begin();
            int node=setit->second;
            int nodedist=setit->first;
            s.erase(s.begin());
            unordered_map<int,list<pair<int,int>>>::iterator mapit=m.find(node);
            if(mapit==m.end())
            {
                continue;
            }
            list<pair<int,int>> l=mapit->second;
            for(list<pair<int,int>>::iterator listit=l.begin();listit!=l.end();listit++)
            {
                int parentdist=dist[node];
                int weight=listit->second;
                if(dist[listit->first]>parentdist+weight)
                {
                    int curr=listit->first;
                    set<pair<int,int>>::iterator f=s.find(make_pair(dist[curr],curr));
                    if(f!=s.end())
                    {
                        s.erase(make_pair(dist[curr],curr));
                    }
                    s.insert(make_pair(parentdist+weight,curr));
                    dist[curr]=parentdist+weight;
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-->"<<dist[i]<<endl;
        }
    }
};
int main()
{
    graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,8,2);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(7,8,7);
    g.shortestpath(0);
}
