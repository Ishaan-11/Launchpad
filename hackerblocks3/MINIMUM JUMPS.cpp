/*
MINIMUM JUMPS
Given an array of integers where each element represents the max number of steps
that can be made forward from that element.
Print the minimum number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

Input Format:
n, size of array Ai, array elements

Constraints:
1<=n<=5000
1<=Ai<=10^5

Output Format:
Number of minimum jumps

Sample Input:
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output:
3
Explanation:
3 (1-> 3 -> 8 ->9)

Time Limit: 1 sec
*/
#include<iostream>
#include<climits>
using namespace std;
int minjumps(int a[],int n)
{
    if(a[0]==0 || n==0)
    {
        return 0;
    }
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i<=a[j]+j)
            {
                dp[i]=dp[j]+1;
                break;
            }
        }
    }
    return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    int a[5001];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<minjumps(a,n);
	return 0;
}
