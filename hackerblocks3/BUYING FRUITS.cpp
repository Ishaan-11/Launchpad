/*
Prateek went to purchase fruits mainly apples, mangoes and oranges.
There are N different fruit sellers in a line.
Each fruit seller sells all three fruit items, but at different prices.
Prateek, obsessed by his nature to spend optimally,
decided not to purchase same fruit from adjacent shops.
Also, Prateek will purchase exactly one type of fruit item (only 1kg) from one shop.
Prateek wishes to spend minimum money buying fruits using this strategy.
Help Prateek determine the minimum money he will spend.
If he becomes happy, he may offer you discount on your favorite course in Coding Blocks ;).
All the best!

Input Format:
First line indicates number of test cases T.
Each test case in its first line contains N denoting the number of fruit sellers in Fruit Market.
Then each of next N lines contains three space separated integers denoting cost of apples,
mangoes and oranges per kg with that particular fruit seller.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
Cost of each fruit(apples/mangoes/oranges) per kg does not exceed 10^4

Output Format:
For each test case, output the minimum cost of shopping taking the mentioned conditions into
account in a separate line.

Sample Input:
1
3
1 50 50
50 50 50
1 50 50
Sample Output:
52
Explanation:
There are two ways, each one gives 52 as minimum cost.
One way is buy apples from first shop, mangoes from second shop and
apples from third shop or he can buy apples from first shop,
oranges from second shop and apples from third shop.

Both ways , cost comes up to 1 + 50 + 1 = 52

Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
int main()
{
    long long int T;
    cin>>T;
    for(long long int t=0;t<T;t++)
    {
        long long int n;
        cin>>n;
        long long int a[n][3],dp[n][3]={};
        for(long long int i=0;i<n;i++)
        {
            for(long long int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        dp[0][0]=a[0][0];dp[0][1]=a[0][1];dp[0][2]=a[0][2];
        for(long long int i=1;i<n;i++)
        {
            //apple
            dp[i][0]=a[i][0]+min(dp[i-1][1],dp[i-1][2]);
            //mango
            dp[i][1]=a[i][1]+min(dp[i-1][0],dp[i-1][2]);
            //orange
            dp[i][2]=a[i][2]+min(dp[i-1][1],dp[i-1][0]);
        }
        long long int x=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
        cout<<x<<endl;
    }
	return 0;
}
