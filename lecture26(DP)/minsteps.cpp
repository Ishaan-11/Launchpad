#include<iostream>
#include<climits>
using namespace std;
//normal
int steps(int n)
{
    if(n==1)
    {
        return 0;
    }
    int a=INT_MAX;
    int b=INT_MAX;
    int c=INT_MAX;
    if(n%3==0)
    {
        a=steps(n/3)+1;
    }
    if(n%2==0)
    {
        b=steps(n/2)+1;
    }
    c=steps(n-1)+1;
    return min(a,min(b,c));
}
//DP
int stepsDP(int n)
{
    int dp[1000]={-1,0,1,1};
    for(int i=4;i<=n;i++)
    {
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        if(i%3==0)
        {
            a=dp[i/3]+1;
        }
        if(i%2==0)
        {
            b=dp[i/2]+1;
        }
        c=dp[i-1]+1;
        dp[i]=min(a,min(b,c));
    }
    return dp[n];
}
int main()
{
    cout<<steps(10)<<endl;
    cout<<stepsDP(5)<<endl;
    return 0;
}
