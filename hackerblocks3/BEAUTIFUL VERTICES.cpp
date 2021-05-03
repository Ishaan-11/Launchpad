/*

You are given a graph with N vertices and M edges.
Master parent is the vertex which has no parent but may have 0 or more children.
In any connected component of the graph, vertex with the lowest value in that component
serves as the master parent. A vertex is called beautiful if it has more children than its parent.
Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.

Input Format:
First line consists of two space separated integers denoting N and M and
the following M lines consist of two space separated integers X and Y denoting there
is an edge between vertices X and Y.

Constraints:
1 <= N <= 100000
0 <= M <= N-1
1 <= x,y <= N

Output Format:
Print the number of beautiful vertices in the graph.

Sample Input:
4 3
1 2
2 3
2 4
Sample Output:
1
Explanation:
In this graph, we have vertices 1,2,3 and 4.
Since 1 is the lowest among these, so it becomes the master vertex.
Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex.
There are no more beautiful vertices in the graph.

Time Limit: 2 sec
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void dfs(vector<int>adj[],bool*vis,int x,int &sum)
{
    if(vis[x])
    {
        return;
    }
    vis[x]=true;
    sum=min(sum,x);
    for(int i=0;i<adj[x].size();i++)
    {
        if(!vis[adj[x][i]])
        {
            dfs(adj,vis,adj[x][i],sum);
        }
    }
    return;
}
void dfs1(vector<int>adj[],bool*vis1,int x,int &ans)
{
    if(vis1[x])
    {
        return;
    }
    vis1[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!vis1[adj[x][i]])
        {
            int child=adj[x][i];
            if(adj[x].size()<adj[child].size())
            {
                ans++;
            }
            dfs1(adj,vis1,child,ans);
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[100005];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool vis[100005]={0};
    bool vis1[100005]={0};
    int a[100005];
    int len=0,sum,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            sum=INT_MAX;
            dfs(adj,vis,i,sum);
            a[len++]=sum;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(!vis1[a[i]])
        {
            dfs1(adj,vis1,a[i],ans);
        }
    }
    cout<<ans<<endl;
	return 0;
}
