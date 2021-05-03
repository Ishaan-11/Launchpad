#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;//no. of vertex
    list<int>* l;
public:
    graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int u,int v,bool bidir=true)//u=start,v=end
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
        return;
    }
    bool check(int v,bool visited[],int parent)
    {
        if(visited[v])
        {
            return true;
        }
        visited[v]=true;
        list<int>::iterator it;
        for(it=l[v].begin();it!=l[v].end();it++)
        {
            if(check(*it,visited,parent))
            {
                return true;
            }
        }
        return false;
    }
    void cycle()
    {
        bool visited[100]={0};
        for(int i=0;i<V;i++)
        {
            if(check(i,visited,i))
            {
                cout<<"cycle";
                return;
            }
        }
        cout<<"no cycle";
        return;
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
    g.cycle();
    return 0;
}
