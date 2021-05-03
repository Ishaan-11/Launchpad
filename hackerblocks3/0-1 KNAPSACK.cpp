/*
You are packing for a vacation on the sea side and you are going to carry only one bag with
capacity S (1 <= S <= 1000). You also have N (1<= N <= 1000) items
that you might want to take with you to the sea side.
Unfortunately you can not fit all of them in the knapsack so you will have to choose.
For each item you are given its size and its value.
You want to maximize the total value of all the items you are going to bring.
What is this maximum total value?

Input Format:
On the first line you are given N and S.
Next line contains N space separated integer which is the size of things and
next line contains the corresponding value of things.

Constraints:
1 <= S,N <= 1000

Output Format:
You should output a single integer on one like -
the total maximum value from the best choice of items for your trip.

Sample Input:
5 4
1 2 3 2 2
8 4 0 5 3
Sample Output:
13
Explanation:
Total capacity = 4. Pick size 1 with value 8 and size 2 with value 5.
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
                continue;
            }
            if(w[j-1]<=i)
            {
                table[i][j]=max(table[i][j-1],p[j-1]+table[i-w[j-1]][j-1]);
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
    cin>>n; cin>>weight;
    int w[n];
    int p[n];
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
