/*
Given a snake and ladder board,
find the minimum number of dice throws required to reach the destination or
last cell from source or 1st cell.
The player has total control over outcome of dice throw and wants to
find out minimum number of throws required to reach last cell.

Input Format:
First line contains integer t as number of test cases.
Each test case contains following input.
First line contains three integers n, l, s which represents the number of cell of board,
number of ladders and number of snakes.
Following l lines contains the description of ladders and next s lines contains description of snakes.

Image

Constraints:
1 < t < 20
1< n,l,s < 50

Output Format:
For each test case you have to print the number which is equal
to the minimum number of dice throws to reach the last cell.

Sample Input:
1
30 4 4
3 22
5 8
11 26
20 29
17 4
19 7
21 9
27 1
Sample Output:
3
Explanation:
Player start from the first cell.
It goes to 1st 3 (then reach at 22) and then 28 and then 30. Total number of dice thrown is 3.
*/
#include<iostream>
#include<list>
#include<queue>
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
    }
    int snl(int src)
    {
        vector<int> dist;
        bool visited[V]={0};
        for(int i=0;i<V;i++)
        {
            dist.push_back(-1);
        }
        dist[src]=0;
        visited[src]=true;
        queue<int> q;
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
                    dist[*it]=dist[top]+1;
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        return dist[V-1]-1;
    }
};
int main()
{
    int t;
    cin>>t;
    for(int T=0;T<t;T++)
    {
        int n;
        cin>>n;
        graph g(n+1);
        for(int i=1;i<n+1;i++)
        {
            for(int j=i+1;j<n+1 && j<=i+6;j++)
            {
                g.addedge(i,j);
            }
        }
        int l,s;
        cin>>l;
        cin>>s;
        for(int i=0;i<l;i++)
        {
            int l1,l2;
            cin>>l1;cin>>l2;
            g.addedge(l1,l2);
        }
        for(int i=0;i<s;i++)
        {
            int l1,l2;
            cin>>l1;cin>>l2;
            g.addedge(l1,l2);
        }
        cout<<g.snl(1);
        cout<<endl;
    }
	return 0;
}
//better
/*
#include<iostream>
#include<list>
#include<queue>
#include<climits>
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
        return;
    }
    int bfs(int src)
    {
        bool visited[V]={0};
        queue<int>q;
        visited[src]=true;
        int dist[V];
        for(int i=0;i<V;i++)
        {
            dist[i]=INT_MAX;
        }
        dist[src]=0;
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
                    visited[*it]=true;
                    dist[*it]=dist[top]+1;
                    q.push(*it);
                }
            }
        }
        return dist[V-1];
    }
};
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,l,s;
        cin>>n>>l>>s;
        int move[n+1]={0};
        for(int i=0;i<l;i++)
        {
            int u,v;
            cin>>u>>v;
            move[u]=v-u;
        }
        for(int i=0;i<s;i++)
        {
            int u,v;
            cin>>u>>v;
            move[u]=v-u;
        }
        graph g(n+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=6 && i+j<=n;j++)
            {
                g.addedge(i,j+i+move[i+j]);
            }
        }
        cout<<g.bfs(1)<<endl;
    }
	return 0;
}
*/
