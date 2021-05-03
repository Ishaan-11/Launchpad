/*
PRINT TRAVERSAL-I
You are given a tree, rooted at node 1. Print the nodes in breadth-first traversal order.

Input Format:
First line contains a single integer N denoting the number of nodes.
Next N-1 lines contains two integers u and v, denoting an undirected edge between node u and node v.
It is guaranteed that these edges form a tree.

Constraints:
1<=N<=10^5
1<=u,v<=N

Output Format:
Print in a single line, the order in which nodes are traversed.

Sample Input:
5
1 2
1 3
2 4
4 5
Sample Output:
1 2 3 4 5
*/
#include<iostream>
#include<queue>
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
    }
    void bfshelper(int v)
    {
        bool visited[V]={0};
        visited[v]=true;
        queue<int>q;
        q.push(v);
        while(!q.empty())
        {
            int top=q.front();
            cout<<top<<" ";
            q.pop();
            list<int>::iterator it;
            for(it=l[top].begin();it!=l[top].end();it++)
            {
                if(!visited[*it])
                {
                    visited[*it]=true;
                    q.push(*it);
                }
            }
        }
        return;
    }

};
int main()
{
    int n;
    cin>>n;
    graph g(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.bfshelper(1);
	return 0;
}
