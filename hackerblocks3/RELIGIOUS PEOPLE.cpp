/*
All the people living in our imaginary world Bitworld are very religious.
There are N cities in Bitworld numbered from 1 to N.
Due to a storm, every road in Bitworld was destroyed and now no temples are left.
There are 2 types of operations :

You can construct a temple by giving away A dollars in ith city.
You can repair an already existing road by giving away B dollars.

Your goal is to make temples such that people of every city have access to some temple.
People of the ith city can visit the temple only if :
A temple exists in that city.
OR
There is a path from that city to a city which contains a temple.
( the path should consist of repaired roads only )
You have to minimize the total cost such that people in every city can go to a temple
and output this minimum cost.

NOTE : You can only repair the roads which existed and not build on your own.

Input Format:
The first line consists of number of test cases T.
Each test case consists of 4 integers N,M,A,B.
which denote number of cities, number of roads which existed ,
cost to build a temple , cost to repair a road.
Next M lines contains M pairs denoted by U V which indicates a road existed between U and V.

Constraints:
1 <= T <= 10.
1 <= N <= 100000.
0 <= M <= 100000.
1 <= A,B <= 1000000000.
1 <= U,V <= N.
Each road connects 2 distinct cities.

Output Format:
Total minimum cost in dollars.

Sample Input:
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
Sample Output:
4
12
Explanation:
For first test case:

build temple in city 1 for 2 dollars.
repair road between 1 and 2 and repair road between 2 and 3 for total cost of 1+1 dollars.
hence total cost is 4 dollars.
For second test case: You can build a temple in every city for a total cost of 6*2 = 12 dollars.

Time Limit: 5 sec
*/
#include<iostream>
#include<queue>
#include<list>
#include<vector>
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
        l[v].push_back(u);
    }
    long int mincost(long int a,long int b,int n)
    {
        if(a<=b)
        {
            return a*(V-1);
        }
        bool visited[V]={0};
        vector<long int>dist;
        for(int i=0;i<V;i++)
        {
            dist.push_back(INT_MAX);
        }
        long int total=0;
        queue<int> q;
        dist[0]=0;
        for(int i=1;i<V;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                total=total+a;//temple build
                dist[i]=0;
                visited[i]=true;
            }
            while(!q.empty())
            {
                int top=q.front();
                q.pop();
                list<int>::iterator it;
                for(it=l[top].begin();it!=l[top].end();it++)
                {
                    if(!visited[*it])
                    {
                        q.push(*it);
                        if(dist[*it]>b)
                        {
                            dist[*it]=b;
                        }
                        visited[*it]=true;
                    }
                }
            }
        }
        long int cost=0;
        for(int i=1;i<V;i++)
        {
            cost=cost+dist[i];
        }
        return cost+total;
    }
};
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,m;
        long int a,b;
        cin>>n;cin>>m;cin>>a;cin>>b;
        graph g(n+1);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u;
            cin>>v;
            g.addedge(u,v);
        }
        cout<<g.mincost(a,b,n)<<endl;
    }
	return 0;
}
//better
/*
#include<iostream>
#include<list>
#include<queue>
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
    long long dfs(int v,bool * visited,long long b)
    {
        long long c=0;
        visited[v]=true;
        queue<int>q;
        q.push(v);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            list<int>::iterator it;
            for(it=l[top].begin();it!=l[top].end();it++)
            {
                if(!visited[*it])
                {
                    c++;
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        return c*b;
    }
    long long mincost(long long a,long long b)
    {
        bool visited[V]={0};
        long long cost=0;
        for(int i=1;i<V;i++)
        {
            if(!visited[i])
            {
                cost+=dfs(i,visited,b)+a;
            }
        }
        return cost;
    }
};
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,m;
        long long a,b;
        cin>>n>>m>>a>>b;
        graph g(n+1);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            g.addedge(u,v);
        }
        if(a<=b)
        {
            long long x=a*n;
            cout<<x<<endl;
        }
        else
        {
            cout<<g.mincost(a,b)<<endl;
        }
    }
	return 0;
}
*/
