/*
VALENTINE MAGIC
It's Valentine's Day in Russia today.
as we all know number of girls in Russia is more than number of boys :P
hence boys have an extra advantage while choosing girl for the valentine evening.
Each boy has certain number of chocolates and each girl has certain number of candies.
Now you being the anchor of evening wants to pair all the boys with
girls such that the sum of absolute difference between boy's chocolate and
girl's candy in a pair is minimized.
Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia :P

Input Format:
The first line consists of two integers N and M. then follow N integers in second line.
Then follow M integers in third line. M >= N

Constraints:
1 <= N <= 5000
1 <= M <= 5000
M >= N
1 <= chocolates <= 1000000
1 <= candies <= 1000000

Output Format:
The only line which consists of required sum of absolute differences.

Sample Input:
2 5
4 5
1 2 3 4 5
Sample Output:
0
Explanation:
we can pair boy numbered 1 with girl numbered 4 and boy numbered 2 with girl numbered 5

Time Limit: 2 sec
*/
#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll boys[5001],girls[5001],dp[5001][5001];
int n,m;
ll ans(int i,int j)
{
    if(i==n)//all boys paired
    {
        return 0;
    }
    if(j==m)//all girls paired but boys still left
    {
        return INT_MAX;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll a=ans(i,j+1);//dont take girl
    ll b=ans(i+1,j+1)+abs(boys[i]-girls[j]);//take that girl
    return dp[i][j]=min(a,b);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>boys[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>girls[i];
    }
    sort(boys,boys+n);
    sort(girls,girls+m);
    cout<<ans(0,0);
	return 0;
}
