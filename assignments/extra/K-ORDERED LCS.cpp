/*
K-ORDERED LCS
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem.
Mancunian was asked to solve the same by an incompetent programmer.
As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced.
A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost
k elements in the first sequence to any value you wish to.
Can you help Mancunian solve this version of the classical problem?

Input Format:
The first line contains three integers N, M and k,
denoting the lengths of the first and second sequences and the value of the provided parameter
respectively. The second line contains N integers denoting the elements of the first sequence.
The third line contains M integers denoting the elements of the second sequence.

Constraints:
1 <= N, M <= 2000
1 <= k <= 5
1 <= element in any sequence <= 109

Output Format:
Print the answer in a new line.

Sample Input:
5 5 1
1 2 3 4 5
5 3 1 4 2
Sample Output:
3
Time Limit: 2 sec
*/
#include<iostream>
#include<cstring>
using namespace std;
int dp[2000][2000][5];
int klcs(int n,int m,int k,int*a,int*b,int i,int j)
{
    if(i==n||j==m)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    int ans=0;
    if(a[i]==b[j])
    {
        ans=1+klcs(n,m,k,a,b,i+1,j+1);
    }
    else
    {
        if(k>0)
        {
            ans=1+klcs(n,m,k-1,a,b,i+1,j+1);
        }
        ans=max(ans,max(klcs(n,m,k,a,b,i,j+1),klcs(n,m,k,a,b,i+1,j)));
    }
    return dp[i][j][k]=ans;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[2000],b[2000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<klcs(n,m,k,a,b,0,0);
	return 0;
}
