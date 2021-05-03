/*
Singh got a new video game and he was playing a shooting game.
There are two birds to kill in this shooting game.
Hitting first bird will provide him X points and hitting second bird will provide him Y points.
And there are 0 points if he misses the bird.

Singh has N coins and it takes 1 coin to try a shoot.
He needs to score a minimum of W points to win the game.

At each turn, he has two choices. The choices include:-

Hitting first bird with probability P1 percent.
However, he might miss it with probability (1-P1) percentage.
Hitting second bird with probability P2 percent.
However, he might miss it with probability (1-P2) percentage.

Help Singh in finding the maximal expected probability (as a percentage b/w 0 and 100)
of winning the shooting game

Input Format:
First line contains the number of test cases T.
Each test case consists of six space separated integers of the
form X Y N W P1 P2 as described in the statement.

Constraints:
1 ≤ T ≤ 10
1 ≤ X,Y ≤ 10
1 ≤ N,W ≤ 10^3
0 ≤ P1,P2 ≤ 100

Output Format:
For each test case, print the result as described above in a separate line.
Note: Choosing to hit any apple is entirely his choice.
Both are independent events meaning P1 + P2 may/may not exceed 100.
Output must contain 6 digits after decimal.

Sample Input:
1
2 3 2 5 50 25
Sample Output:
12.500000
Explanation:
Singh is getting 2 points from shooting first bird and 3 points from shooting second Apple.


Singh had 2 chances to shoot and he need to score atleast 5 points so anyhow he need to shoot
bird 1 in one shoot and bird 2 in another shoot , if he wants to win.

The maximum probability of winning is 0.5 * 0.25 = 0.125 = 12.5%
*/
#include<iostream>
#include<iomanip>
using namespace std;
double solve(double dp[][1000],int n,int w,int x,int y,double p1,double p2)
{
    if(w<=0)
    {
        return 1.0;
    }
    if(n<=0)
    {
        return 0.0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    double c1=p1*solve(dp,n-1,w-x,x,y,p1,p2)+(1-p1)*solve(dp,n-1,w,x,y,p1,p2);
    double c2=p2*solve(dp,n-1,w-y,x,y,p1,p2)+(1-p2)*solve(dp,n-1,w,x,y,p1,p2);
    return dp[n][w]=max(c1,c2);
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int x,y,n,w;
        double p1,p2;
        cin>>x>>y>>n>>w>>p1>>p2;
        p1=double(p1)/100.0;
        p2=double(p2)/100.0;
        double dp[1000][1000];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                dp[i][j]=-1;
            }
        }
        double ans=solve(dp,n,w,x,y,p1,p2)*100.0;
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
	return 0;
}
