/*
Given a set of "n" non-negative integers, and a value "sum",
determine if there is a subset of the given set with sum equal to given sum.

Input Format:
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints:
1<= n <= 5000
1<= sum <= 10^7
1<= Ai <=10^5

Output Format:
Yes, if sum exist No, it sum does not exist

Sample Input:
5 10
1 2 3 4 5
Sample Output:
Yes
Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
bool subset(int set[],int n,int sum)
{
    bool dp[sum+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=true;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[i][0]=false;
    }
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(i>=set[j-1])
            {
                dp[i][j]=dp[i][j] || dp[i-set[j-1]][j-1];
            }
        }
    }
    return dp[sum][n];
}
int main()
{
    int n,sum,set[5000];
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>set[i];
    }
    if(subset(set,n,sum))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
	return 0;
}
