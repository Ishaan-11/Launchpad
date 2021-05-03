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
    bool cyclecheck(int v,bool visited[],int parent)
    {
        if(visited[v])
        {
            return true;
        }
        visited[v]=true;
        list<int>::iterator it;
        for(it=l[v].begin();it!=l[v].end();it++)
        {
            if(*it!=parent)
            {
                bool cycle=cyclecheck(*it,visited,v);
                if(cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool cycledetect()
    {
        bool visited[100]={0};
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool cycle=cyclecheck(i,visited,i);
                if(cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    //g.addedge(0,3);
    g.addedge(1,4);
    g.addedge(2,3);
    //g.addedge(2,4);
    //g.addedge(3,4);
    cout<<g.cycledetect();
    return 0;
}
