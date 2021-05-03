/*
OPTIMAL GAME STRATEGY-II
Piyush and Nimit are playing a coin game.
They are given n coins with values x1, x2 …. xn where 'n' is always even.
They take alternate terms. In each turn, a player picks either the first coin or the
last coin from the row and removes it from the row. The value of coin is received by that player.
Determine the maximum value that piyush can win if he moves first. Both the players play optimally.

Input Format:
First line contains the number of coins 'n'.
Second line contains n space separated integers which is the value of ith coin.

Constraints:
N <= 10000

Output Format:
Print a single line with the maximum possible value.

Sample Input:
4
1 2 3 4
Sample Output:
6
Explanation:
Piyush will pick the coin 4. Then nimit can pick either 1 or 3.
In both the cases piyush picks coin 2 and wins with a total of 6
*/
#include<iostream>
using namespace std;
int dp[10000][10000]={};
int game(int*a,int i ,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    int beg=a[i]+min(game(a,i+2,j),game(a,i+1,j-1));
    int end=a[j]+min(game(a,i,j-2),game(a,i+1,j-1));
    return dp[i][j]=max(beg,end);
}
int main()
{
        int n;
        cin>>n;
        int a[10000];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<game(a,0,n-1);
	return 0;
}
