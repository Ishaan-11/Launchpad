/*
Harry Potter has n mixtures in front of him, arranged in a row.
Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together.
At each step, he is going to take two mixtures that stand next to each other and mix them together,
and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process.
The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
You can find the original problem here.


Input Format:
The first line of each input file will contain n, the number of mixtures.
The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Constraints:
1 <= n <= 100

Output Format:
Output the minimum amount of smoke.

Sample Input:
3
40 60 20
Sample Output:
2400
Explanation:
There are two possibilities: first mix 40 and 60 (smoke: 2400), getting 0,
then mix 0 and 20 (smoke: 0); total amount of smoke is 2400. first mix 60 and 20 (smoke: 1200),
getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400.
The first scenario is a much better way to proceed.

Time Limit: 1 sec
*/
#include<iostream>
#include<climits>
using namespace std;
int sum(int a[],int s,int e)
{
    int x=0;
    for(int i =s;i<=e;i++)
    {
        x+=a[i];
        x%=100;
    }
    return x;
}
int count(int a[],int dp[][100],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        dp[i][j]=min(dp[i][j],count(a,dp,i,k)+count(a,dp,k+1,j)+sum(a,i,k)*sum(a,k+1,j));
    }
    return dp[i][j];
}
int main()
{
    int n;
    cin>>n;
    int a[100],dp[100][100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<count(a,dp,0,n-1);
	return 0;
}
