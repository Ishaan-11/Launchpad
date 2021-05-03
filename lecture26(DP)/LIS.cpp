#include<iostream>
#include<climits>
using namespace std;
int LIS(int arr[],int n)
{
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<=arr[i] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    int m=INT_MIN;
     /*for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }*/
    for(int i=0;i<n;i++)
    {
        if(dp[i]>m)
        {
            m=dp[i];
        }
    }
    return m;
}
int main()
{
    int arr[10]={10,2,5,15,26,17,5,75};
    cout<<LIS(arr,8);
    return 0;
}
