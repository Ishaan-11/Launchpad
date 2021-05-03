/*
Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node
'S' represents the starting position and an edge between two nodes is of a given length,
which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node 'S')
to all of the other nodes in the graph.

If a node is unreachable, the distance is assumed as -1.

Input Format:
The first line contains T, denoting the number of test cases.
First line of each test case has two integers N,
M denoting the number of nodes in the graph and, denoting the number of edges in the graph.

The next M lines each consist of three space-separated integers x,y,r
where x and y denote the two nodes between which the undirected edge exists,
'r' denotes the length of edge between these corresponding nodes.

The last line has an integer, 'S' denoting the starting position.

Constraints:
1 <= N <= 3000
1 <= M <= (N*(N-1))/2
1 <= x,y <= N
1 <= r <= 10^5

Output Format:
For each of the T test cases, print a single line consisting N-1 space separated integers
denoting the shortest distance of N-1 nodes other than from starting
position S in increasing order of their labels.

For unreachable nodes, print -1.

Sample Input:
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

Sample Output:
24 3 15
Time Limit: 2 sec
*/
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
    void addedge(int src,int dest,int weight)
    {
        m[src].push_back(make_pair(dest,weight));
        m[dest].push_back(make_pair(src,weight));
    }
    void shortestpath(int src)
    {
        vector<int> dist;
        bool visited[V]={0};
        for(int i=0;i<V;i++)
        {
            dist.push_back(INT_MAX);
        }
        dist[src]=0;
        visited[src]=true;
        set<pair<int,int>> s;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto setit=s.begin();
            int node=setit->second;
            s.erase(s.begin());
            auto mapit=m.find(node);
            if(mapit==m.end())
            {
                continue;
            }
            auto l=mapit->second;
            for(auto listit=l.begin();listit!=l.end();listit++)
            {
                int parentdist=dist[node];
                int weight=listit->second;
                int curr=listit->first;
                visited[curr]=true;
                if(dist[curr]>parentdist+weight)
                {
                    auto f=s.find(make_pair(dist[curr],curr));
                    if(f!=s.end())
                    {
                        s.erase(make_pair(dist[curr],curr));
                    }
                    s.insert(make_pair(parentdist+weight,curr));
                    dist[curr]=parentdist+weight;
                }
            }
        }
        for(int i=1;i<V;i++)
        {
            if(i==src)
            {
                continue;
            }
            if(visited[i])
            {
                cout<<dist[i]<<" ";
            }
            else
            {
                cout<<"-1"<<" ";
            }
        }
    }
};
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n;//nodes
        cin>>m;//edges
        graph g(n+1);
        for(int j=1;j<=m;j++)
        {
            int x,y,r;
            cin>>x;
            cin>>y;
            cin>>r;
            g.addedge(x,y,r);
        }
        int s;
        cin>>s;
        g.shortestpath(s);
        cout<<endl;
    }
	return 0;
}
