#include<iostream>
using namespace std;
//recursion
int fiboR(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fiboR(n-1)+fiboR(n-2);
}
//memoisation
int arr[1000];//global array
int fiboM(int n)
{
    if(n==0)
    {
        arr[0]=0;
        return 0;
    }
    if(n==1)
    {
        arr[1]=1;
        return 1;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    arr[n]=fiboM(n-1)+fiboM(n-2);
    return arr[n];
}
//DP
int fiboDP(int n)
{
    int dp[1000]={0,1};
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    cout<<fiboR(6)<<endl;
    for(int i=0;i<1000;i++)
    {
        arr[i]=-1;
    }
    cout<<fiboM(6)<<endl;
    cout<<fiboDP(6);
    return 0;
}
