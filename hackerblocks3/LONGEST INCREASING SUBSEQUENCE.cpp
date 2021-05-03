/*
Find the length of the longest subsequence in a given array of integers
such that all elements of the subsequence are sorted in strictly ascending order.

Input Format:
The first line contains a single integer n.
Next line contains n space separated numbers which are 0<a<10^5

Constraints:
0< n< 10^5

Output Format:
Print a single line containing a single integer denoting
the length of the longest increasing subsequence.

Sample Input:
6
50 3 10 7 40 80
Sample Output:
4
Explanation:
The longest subsequence in test case is - 3,7,40,80
*/
#include<iostream>
using namespace std;
int lis(int a[],int n)
{
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<=a[i] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(m<dp[i])
        {
            m=dp[i];
        }
    }
    return m;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<lis(a,n);
	return 0;
}
