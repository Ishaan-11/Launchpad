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
        return ;
    }
    bool cyclecheck(int v,bool visited[],bool visited2[])
    {
        if(visited[v]==false)
        {
            visited[v]=true;
            visited2[v]=true;
            list<int>::iterator it;
            for(it=l[v].begin();it!=l[v].end();it++)
            {
                if(!visited[*it] && cyclecheck(*it,visited,visited2))
                {
                    return true;
                }
                if(visited2[*it])
                {
                    return true;
                }
            }
            visited2[v]=false;
            return false;
        }
    }
    bool cycledetect()
    {
        bool visited[100]={0};
        bool visited2[100]={0};
        for(int i=1;i<V;i++)
        {
            if(cyclecheck(i,visited,visited2))
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    graph g(7);
    g.addedge(1,2,0);
    g.addedge(1,4,0);
    g.addedge(2,5,0);
    g.addedge(2,3,0);
    g.addedge(3,4,0);
    g.addedge(6,4,0);
    //g.addedge(4,2,0);
    cout<<g.cycledetect();
    return 0;
}

