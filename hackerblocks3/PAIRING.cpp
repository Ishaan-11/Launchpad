/*
There are N cities numbered from 0 to N-1.
You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y)
i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format:
The first line contains two integers, N and M separated by a single space.
M lines follow.
Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints:
1 <= N <= 100000
1 <= M <= 100000
0 <= X,Y <= N-1

Output Format:
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input:
5 3
0 1
2 3
0 4
Sample Output:
6
Explanation:
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and
also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.

Time Limit: 2 sec
*/
#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;
    list<int> * l;
    public:
    graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void way(int vertex,bool visited[],int &c)
    {
        if(visited[vertex])
        {
            return;
        }
        visited[vertex]=true;
        c++;
        list<int>::iterator it;
        for(it=l[vertex].begin();it!=l[vertex].end();it++)
        {
            way(*it,visited,c);
        }
        return;
    }
    void dfs()
    {
        bool visited[V]={0};
        int sum=0,node=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                int c=0;
                way(i,visited,c);
                sum=sum+node*c;
                node=node+c;
            }
        }
        cout<<sum;
    }
};
int main()
{
    int n,m;
    cin>>n;//nodes
    cin>>m;//edges
    graph g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        g.addedge(u,v);
    }
    g.dfs();
	return 0;
}
//better
/*
#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;
    list<int> *l;
    public:
    graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
        return;
    }
    int dfs(int v,bool* visited)
    {
        if(visited[v])
        {
            return 0;
        }
        visited[v]=true;
        int c=1;
        list<int>::iterator it;
        for(it=l[v].begin();it!=l[v].end();it++)
        {
            c=c+dfs(*it,visited);
        }
        return c;
    }
    int pairing()
    {
        bool visited[V]={0};
        int c=(V*(V-1))/2;
        //cout<<c<<" ";
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                int x=dfs(i,visited);
                //cout<<x<<" ";
                c-=(x*(x-1))/2;
            }
        }
        return c;
    }
};
int main()
{
        int n,m;
        cin>>n>>m;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            g.addedge(u,v);
        }
        cout<<g.pairing();
	return 0;
}
*/
