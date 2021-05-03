/*
HOLI
Nowadays, people have many ways to save money on accommodation when they are on vacation.
One of these ways is exchanging houses with other people.

Here is a group of N people who want to travel around the world.
They live in different cities,
so they can travel to some other people's city and use someone's house temporary.
Now they want to make a plan that chooses a destination for each person.
There are two rules should be satisfied:

All the people should go to one of the other people's city.
Two of them never go to the same city, because they are not willing to share a house.
They want to maximize the sum of all people's travel distance.
The travel distance of a person is the distance between the city he lives in and the city he travels to.
These N cities have N-1 highways connecting them.
The travelers always choose the shortest path when traveling.

Given the highways' information, it is your job to find the best plan,
that maximum the total travel distance of all people.

Input Format:
He first line of input contains one integer T, indicating the number of test cases.
Each test case contains several lines.
The first line contains an integer N, representing the number of cities.
Then the following N-1 lines each contains three integers X, Y, Z,
means that there is a highway between city X and city Y, and length of that highway.

You can assume all the cities are connected and the highways are bi-directional.

Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 10*5
1 ≤ X, Y ≤ N
1 ≤ Z ≤ 10^6

Output Format:
For each test case in the input, print one line: "Case #X: Y",
where X is the test case number (starting with 1) and
Y represents the largest total travel distance of all people.

Sample Input:
2
4
1 2 3
2 3 2
4 3 2
6
1 2 3
2 3 4
2 4 1
4 5 8
5 6 5
Sample Output:
Case #1: 18
Case #2: 62
*/
#include<iostream>
#include<list>
#define ll long long
using namespace std;
class graph
{
    int V;
    list<pair<int,ll>> *l;
    public:
    graph(int v)
    {
        V=v;
        l=new list<pair<int,ll>>[V];
    }
    void addedge(int u,int v,ll w)
    {
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }
    int dfs(int node,bool * visited,int * count,ll &ans)
    {
        visited[node]=true;
        count[node]=1;
        list<pair<int,ll>>::iterator it;
        for(it=l[node].begin();it!=l[node].end();it++)
        {
            int v=it->first;
            if(!visited[v])
            {
                count[node]+=dfs(v,visited,count,ans);
                int c=count[v];
                ll cost=it->second;
                ans+= 2*min(c,(V-1)-c)*cost;
            }
        }
        return count[node];
    }
    ll holi()
    {
        bool visited[V]={0};
        int count[V]={0};
        ll ans=0;
        dfs(1,visited,count,ans);
        return ans;
    }
};
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        graph g(n+1);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            ll w;
            cin>>u>>v>>w;
            g.addedge(u,v,w);
        }
        cout<<"Case #"<<t<<": "<<g.holi()<<endl;
    }
	return 0;
}
