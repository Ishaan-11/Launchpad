/*
Given a big amount N and the array of denominations S.
Assuming infinite supply of each of S = {S1,S2….Sm} denominations,
find the number of ways to make change for N cents.

Input Format:
First line contains an integer T denoting the total number of test cases.
For every test case, there are three lines.
First line will contain an integer 'M' denoting the size of array.
The second line contains M space-separated integers A1, A2, …, Am denoting the elements of the array.
The third line contains an integer 'N' denoting the cents.

Constraints:
1 <= T <= 10
1 <= n <= 500
1 <= S[i] <= 1000
1 <= N <= 1000000

Output Format:
Print number of possible ways to make change for N cents in a new line.
Since answers can be large, print answer % (1000000000 + 7).

Sample Input:
2
3
1 2 3
4
4
2 5 3 6
10
Sample Output:
4
5
Explanation:
For N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.
So output should be 4. For N = 10 and S = {2, 5, 3, 6},
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.

Time Limit: 2 sec
*/
#include<iostream>
using namespace std;
#define mod 1000000007
//int dp[1000000][501];

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int m;
        cin>>m;
        int a[501];
        for(int i=1;i<=m;i++)
        {
            cin>>a[i];
        }
        int n;
        cin>>n;
        int** dp = new int*[n+1];
        for(int i = 0; i <= n; ++i)
        {
            dp[i] = new int[m+1];
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                {
                    dp[i][j]=1;
                }
                else if(j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=dp[i][j-1]%mod;
                    if(i-a[j]>=0)
                    {
                        dp[i][j]=((dp[i][j]%mod)+(dp[i-a[j]][j]%mod))%mod;
                    }
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
	return 0;
}
