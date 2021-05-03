/*
EXPAND THE POND
You are given a matrix with N rows and M columns.
Each cell is either dry or has water.
We say that two cells are neighbours if they share one of their four sides.
A pond is a maximal subset of cells containing water such that any cell is accessible
from any other cell by moving only along neighbours.
You should add water to exactly one cell in order to maximise the size of the pond.

Input Format:
The first line contains two integers N and M.
Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.

Constraints:
1 ≤ N,M ≤ 1000
There is at least one dry cell and one cell filled with water in the matrix.

Output Format:
Print a single integer representing the largest possible size of the pond.

Sample Input:
3 3
0 1 1
0 0 1
0 1 0
Sample Output:
5
Explanation:
Watering the cell at coordinates [2,2] unites the 2 ponds with sizes 1 and 3,
resulting a pond of size 5, including the newly watered cell.

Time Limit: 4 sec
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<climits>
#define ll long long
using namespace std;
int r,c;
ll dfs(ll i,ll j,vector<vector<ll>>&a,ll timer)
{
    a[i][j]=timer;
    ll ct=1;
    if(i-1>0 && a[i-1][j]==1)
    {
        ct+=dfs(i-1,j,a,timer);
    }
    if(i+1<=r && a[i+1][j]==1)
    {
        ct+=dfs(i+1,j,a,timer);
    }
    if(j-1>0 && a[i][j-1]==1)
    {
        ct+=dfs(i,j-1,a,timer);
    }
    if(j+1<=c && a[i][j+1]==1)
    {
        ct+=dfs(i,j+1,a,timer);
    }
    return ct;
}
int main()
{
    cin>>r>>c;
    vector<vector<ll>>a(r+1);
    for(ll i=1;i<=r;i++)
    {
        a[i].resize(c+1);
        for(ll j=1;j<=c;j++)
        {
            cin>>a[i][j];
        }
    }
    ll ans=INT_MIN;
    unordered_map<ll,ll>m;
    ll timer=2;
    for(ll i=1;i<=r;i++)
    {
        for(ll j=1;j<=c;j++)
        {
            if(a[i][j]==1)
            {
                m[timer]=dfs(i,j,a,timer);
                ans=max(ans,m[timer]);
                timer++;
            }
        }
    }
    for(ll i=1;i<=r;i++)
    {
        for(ll j=1;j<=c;j++)
        {
            if(a[i][j]==0)
            {
                set<ll> s;
                if(i-1>0 && a[i-1][j]>1)
                {
                    s.insert(a[i-1][j]);
                }
                if(i+1<=r && a[i+1][j]>1)
                {
                    s.insert(a[i+1][j]);
                }
                if(j-1>0 && a[i][j-1]>1)
                {
                    s.insert(a[i][j-1]);
                }
                if(j+1<=c && a[i][j+1]>1)
                {
                    s.insert(a[i][j+1]);
                }
                ll sum=1;
                set<ll>:: iterator it;
                for(it=s.begin();it!=s.end();it++)
                {
                    sum+=m[*it];
                }
                ans=max(ans,sum);
            }
        }
    }
    cout<<ans;
	return 0;
}
