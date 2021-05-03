/*
You've heard of 0-1 knapsack. Below is the problem statement for the same.

Given weights and values of n items,
put these items in a knapsack of capacity cap to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1]
which represent values and weights associated with n items respectively.
Also given an integer cap which represents knapsack capacity,
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller
han or equal to cap. You cannot break an item, either pick the complete item,
or don’t pick it (0-1 property).
There is a little twist for 0-N knapsack.
You can pick an element more than once.
Now you have to find maximum value multi subset of val[] such that sum of the weights of this
subset is smaller than or equal to cap.

Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

Input Format:
The first line contains two integers, representing n(size of val[]) and cap respectively.
The subsequent line contains n integers representing the wt[] array.
The next line, again, contains n integers representing the val[] array.

Constraints:
1 <= n,cap <= 1000
1 <= wt[i] <= cap
1 <= val[i] <= 100000

Output Format:
Print a single integer, the answer to the problem.

Sample Input:
5 11
3 2 4 5 1
4 3 5 6 1
Sample Output:
16
Explanation:
We take second item 4 times and fifth item one time to make the total values 16.

Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
int knapsack(int p[],int w[],int n,int weight)
{
    int table[weight+1][n+1];
    for(int i=0;i<weight+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            if(w[j-1]<=i)
            {
                table[i][j]=max(table[i][j-1],p[j-1]+table[i-w[j-1]][j]);
            }
            else
            {
                table[i][j]=table[i][j-1];
            }
        }
    }
    return table[weight][n];
}
int main()
{
    int n,weight;
    cin>>n;
    cin>>weight;
    int w[n],p[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<knapsack(p,w,n,weight);
	return 0;
}
