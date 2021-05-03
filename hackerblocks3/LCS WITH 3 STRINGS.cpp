/*
Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.

Input Format:
First line contains first string . Second line contains second string.
Third line contains the third string.

Constraints:
The length of all strings is |s|< 200

Output Format:
Output an integer denoting the length of longest common subsequence of above three strings.

Sample Input:
GHQWNV
SJNSDGH
CPGMAH
Sample Output:
2
Explanation:
"GH" is the longest common subsequence

Time Limit: 3 sec
*/
#include<iostream>
using namespace std;
int lcs(string a,string b,string c)
{
    int x=a.length();
    int y=b.length();
    int z=c.length();
    int dp[x+1][y+1][z+1];
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            for(int k=0;k<=z;k++)
            {
                if(i==0||j==0||k==0)
                {
                    dp[i][j][k]=0;
                }
                else if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])
                {
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[x][y][z];
}
int main()
{
    string a,b,c;
    cin>>a; cin>>b; cin>>c;
    cout<<lcs(a,b,c);
	return 0;
}
