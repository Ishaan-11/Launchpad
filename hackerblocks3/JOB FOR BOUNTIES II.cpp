/*
Mike is given N jobs and each job i is characterized by duration[i]
(time taken to complete ith job), reward[i] (bounties he will get on finishing ith job)
and deadline[i] (the time upto which ith job must be completed if it is to be done).
He has T time and can do at most one job at a time.
Now, he has to choose jobs maximizing the number of bounties he can get after T time units.


Input Format:
The first line contains two integers, T and n, separated by space.
The next line contains N integers, separated by spaces, ith integer representing reward[i].
The next line contains N integers, separated by spaces, ith integer representing duration[i].
The next line contains N integers, separated by spaces, ith integer representing deadline[i].

Constraints:
1 <= N <= 100
1 <= T,duration[i],reward[i],deadline[i] <= 1000

Output Format:
Print maximum number of bounties Mike can get after T time units.

Sample Input:
20 5
4 3 2 5 4
7 6 4 6 6
9 13 12 13 20
Sample Output:
13
Explanation:
Mike can do first, forth and fifth jobs to get 13 bounties (4+5+4) in the given order.

Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
int main()
{
    int T,n;
    cin>>T>>n;
    long long int dp[1001][101],reward[1001],duration[1001],deadline[1001];
    for(int i=0;i<n;i++)
    {
        cin>>reward[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>deadline[i];
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=T;i++)
    {
        dp[i][0]=0;
    }
    long long int ans=0;
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(duration[j-1]<=i && deadline[j-1]>=i)
            {
                dp[i][j]=max(dp[i][j],reward[j-1]+dp[i-duration[j-1]][j-1]);
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans;
	return 0;
}
