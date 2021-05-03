/*
EXCHANGING COINS
Tughlaq introduces a strange monetary system.
He introduces copper coins and each coin has a number written on it.
A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4.
A coin can also be sold for gold.
One can get as much grams of gold as the number written on the coin.
You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format:
The input file contains a single integer n, the number on the coin.

Constraints:
0 <= n <= 1 000 000 000

Output Format:
Print the maximum weight of gold you can get.

Sample Input:
12
Sample Output:
13
Time Limit: 2 sec
*/
#include<iostream>
using namespace std;
long long int count(long long int memo[],long long int n)
{
    if(n<=1000000 && memo[n]!=-1)
    {
        return memo[n];
    }
    if(n<=11)
    {
        return memo[n]=n;
    }
    long long int x=max(n,count(memo,n/2)+count(memo,n/3)+count(memo,n/4));
    if(n<=1000000)
    {
        memo[n]=x;
    }
    return x;
}
int main()
{
    long long int n;
    cin>>n;
    long long int memo[1000000];
    for(long long int i=0;i<=1000000;i++)
    {
        memo[i]=-1;
    }
    cout<<count(memo,n);
	return 0;
}
