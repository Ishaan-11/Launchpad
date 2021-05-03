/*
Consider an undirected graph consisting of 'n' nodes where
each node is labeled from 1 to n and the edge between any two nodes is always of length 6 .
We define node 's' to be the starting position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' ,
perform each query by calculating the shortest distance from starting node 's'
to all the other nodes in the graph. Then print a single line of n-1 space-separated integers
listing node s's shortest distance to each of the n-1 other nodes
(ordered sequentially by node number); if 's' is disconnected from a node,
print -1 as the distance to that node.


Input Format:
The first line contains an integer,q , denoting the number of queries.
The subsequent lines describe each query in the following format:

Each line contains N and M, the number of nodes and edges respectively.

The next m lines contains u and v means that there is edge between u and v .

The last line contains 's', the starting node.

Constraints:
1 <= q <= 10
2 <= n <= 1000
1 <= m <= (n*(n-1))/2
1 <= u,s,v <= n

Output Format:
You have to print n-1 integer denoting the shortest distance from s to
all other nodes excluding s itself.

Sample Input:
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output:
6 6 -1
-1 6
Time Limit: 3 sec
*/
#include<iostream>
#include<queue>
#include<list>
#include<vector>
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
    }
    void shortestpath(int src)
    {
        queue<int> q;
        bool visited[V]={0};
        vector<int> dist;
        for(int i=0;i<V;i++)
        {
            dist.push_back(-1);
        }
        dist[src]=0;
        visited[src]=true;
        q.push(src);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            list<int>::iterator it;
            for(it=l[top].begin();it!=l[top].end();it++)
            {
                if(!visited[*it])
                {
                    dist[*it]=dist[top]+6;
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        for(int i=1;i<V;i++)
        {
            if(i==src)
            {
                continue;
            }
            cout<<dist[i]<<" ";
        }
    }
};
int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int n,m;
        cin>>n;//nodes
        cin>>m;//edges
        graph g(n+1);
        for(int j=0;j<m;j++)
        {
            int u,v;
            cin>>u;
            cin>>v;
            g.addedge(u,v);
        }
        int s;
        cin>>s;
        g.shortestpath(s);
        cout<<endl;
    }
	return 0;
}
