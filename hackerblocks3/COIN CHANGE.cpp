/*
Given a value N, if we want to make change for N cents,
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
In how many ways can we make the change? The order of coins doesn’t matter.

Input Format:
First line of input contain two space separated integers N and M.
Second line of input contains M space separated integers - value of coins.

Constraints:
1<=N<=250
1<=m<=50
1 <= Si <= 50

Output Format:
Output a single integer denoting the number of ways to make the given change using
given coin denominations.

Sample Input:
10 4
2 5 3 6
Sample Output:
5
*/
#include<iostream>
using namespace std;
int change(int n,int coin[],int size)
{
    int table[n+1][size+1];
    for(int i=0;i<n+1;i++)
    {
        table[i][0]=0;
    }
    for(int j=0;j<size+1;j++)
    {
        table[0][j]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<size+1;j++)
        {
            //without j
            int a=table[i][j-1];
            //with j
            int b=0;
            if(i-coin[j-1]>=0)
            {
                b=table[i-coin[j-1]][j];
            }
            table[i][j]=a+b;
        }
    }
    return table[n][size];
}
int main()
{
    int n,size;
    cin>>n;
    cin>>size;
    int coin[size];
    for(int i=0;i<size;i++)
    {
        cin>>coin[i];
    }
    cout<<change(n,coin,size);
	return 0;
}
