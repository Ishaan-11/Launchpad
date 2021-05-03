/*
CHICAGO - 106 MILES TO CHICAGO
In the movie "Blues Brothers",
the orphanage where Elwood and Jake were raised may be sold to the Board of Education
if they do not pay 5000 dollars in taxes at the Cook County Assessor's Office in Chicago.
After playing a gig in the Palace Hotel ballroom to earn these 5000 dollars,
they have to find a way to Chicago. However, this is not as easy as it sounds,
since they are chased by the Police, a country band and a group of Nazis.
Moreover, it is 106 miles to Chicago, it is dark and they are wearing sunglasses.
As they are on a mission from God, you should help them find the safest way to Chicago.
In this problem, the safest way is considered to be the route which
maximizes the probability that they are not caught.

For more stricter evaluation of your code, try submitting your solution here.

Input Format:
The input file contains several test cases.
Each test case starts with two integersn and m .
n is the number of intersections, m is the number of streets to be considered.
The next m lines contain the description of the streets.
Each street is described by a line containing 3 integers a, band p;
a and b are the two end points of the street and p is the probability in percent that
the Blues Brothers will manage to use this street without being caught.
Each street can be used in both directions.
You may assume that there is at most one street between two end points.
The last test case is followed by a zero.

Constraints:
1 ≤ a, b ≤ n , a ≠ b,
1 ≤ p ≤ 100
2 ≤ n ≤ 100 ,
1 ≤ m ≤ n*(n-1)/2

Output Format:
For each test case, calculate the probability of the safest path from intersection 1 (
the Palace Hotel) to intersection n (the Honorable Richard J.
Daley Plaza in Chicago).
You can assume that there is at least one path between intersection 1 and n.
Print the probability as a percentage with exactly 6 digits after the decimal point.
Adhere to the format shown below and print one line for each test case.

Sample Input:
5 7
5 2 100
3 5 80
2 3 70
2 1 50
3 4 90
4 1 85
3 1 70
0
Sample Output:
61.200000 percent
*/
#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
#define ll long long
using namespace std;
ll n,e;
vector<vector<pair<ll,double>>> adj;
double inverseDijikstra()
{
    vector<double> dis(n+1,0.0);
    vector<bool> done(n+1,false);
    dis[1]=1.0;
    priority_queue<pair<double,ll>>q;
    q.push(make_pair(1.0,1));
    while(!q.empty())
    {
        pair<double,ll> p=q.top();
        q.pop();
        int node=p.second;
        int prob=p.first;
        done[node]=true;
        int sz=adj[node].size();
        for(int i=0;i<sz;i++)
        {
            ll ch=adj[node][i].first;
            double pp=adj[node][i].second;
            if(done[ch])
            {
                continue;
            }
            if(dis[ch]<dis[node]*pp)
            {
                dis[ch]=dis[node]*pp;
                q.push(make_pair(dis[ch],ch));
            }
        }
    }
    return dis[n];
}
int main()
{
    while(true)
    {
        cin>>n;
        if(n==0)
        {
            break;
        }
        cin>>e;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<e;i++)
        {
            ll u,v;
            double p;
            cin>>u>>v>>p;
            p=p/100.0;
            adj[u].push_back(make_pair(v,p));
            adj[v].push_back(make_pair(u,p));
        }
        double prob=inverseDijikstra();
        cout<<fixed<<setprecision(6)<<prob*100.0<<" percent"<<endl;
    }
	return 0;
}
