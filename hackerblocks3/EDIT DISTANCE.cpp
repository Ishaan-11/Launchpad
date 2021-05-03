/*
You are given 2 strings s1 and s2. You can perform the following operations on them:

Insert a character at any position.
Remove a character from any position.
Replace a character with any other character.
Find the minimum number of these operations required to convert s1 to s2.

Input Format:
First line contains string s1. Second line contains string s2.

Constraints:
1<=|s1|,|s2|<=2000
s1 and s2 contains only lowercase English letters.

Output Format:
Print a single integer denoting the minimum number of operations required.

Sample Input:
abcde
bcdae
Sample Output:
2
Explanation:
First delete 'a' from position 1 in s1 and then insert 'a' at position 4.

Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
int editdist(string inp,string out)
{
    int x=inp.length();
    int y=out.length();
    int dp[x+1][y+1];
    dp[0][0]=0;
    for(int i=1;i<y+1;i++)
    {
        dp[0][i]=dp[0][i-1]+1;
    }
    for(int i=1;i<x+1;i++)
    {
        dp[i][0]=dp[i-1][0]+1;
    }
    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            if(inp[i-1]==out[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
                continue;
            }
            int ins=1+dp[i][j-1];
            int del=1+dp[i-1][j];
            int rep=1+dp[i-1][j-1];
            dp[i][j]=min(ins,min(del,rep));
        }
    }
    return dp[x][y];
}
int main()
{
    string inp,out;
    cin>>inp;
    cin>>out;
    cout<<editdist(inp,out);
	return 0;
}
