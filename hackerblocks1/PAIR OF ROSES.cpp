/*

Deepak has limited amount of money which he can spend on his girlfriend.
So he decided to buy two roses for her.
Since roses are of varying sizes, their prices are different.
Deepak wishes to completely spend that fixed amount of money on buying roses.
As he wishes to spend all the money,
he should choose a pair of roses whose prices when summed up are equal to the money that he has.
Help Deepak choose such a pair of roses for his girlfriend.
NOTE: If there are multiple solutions
print the solution that minimizes the difference between the prices i and j.
After each test case you must print a blank line.


Input Format:
First line indicates the number of test cases.
Then, in the next line, the number of available roses, N is given.
Next line will have N integers, representing the price of each rose, a rose costs less than 1000001.
Then there is another line with an integer M, representing how much money Deepak has.
There is a blank line after each test case.

Constraints:
1≤ T ≤100
2 ≤ N ≤ 10000
Price[i]<1000001
Output Format:
For each test case you must print the message:
‘Deepak should buy roses whose prices are i and j.’,
where i and j are the prices of the roses whose sum is equal do M and i ≤ j.
 You can consider that it is always possible to find a solution,
 if there are multiple solutions print
the solution that minimizes the difference between the prices i and j.
After each test case you must print a blank line.

Sample Input:
2
2
40 40
80

5
10 2 6 8 4
10
Sample Output:
Deepak should buy roses whose prices are 40 and 40.
Deepak should buy roses whose prices are 4 and 6.
Explanation:
Find two such kind of price of roses which has sum up equal to Deepak's Money.

Time Limit: 3 sec
*/
#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int t,n,m,x;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n;
        int a[n],s=INT_MAX,ii=0,jj=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int c=0;
                if((a[i]+a[j])==m)
                {
                    if(a[i]>=a[j])
                    {
                        c++;
                     x=a[i]-a[j];
                    }
                    else
                    {
                        x=a[j]-a[i];
                    }
                    if(x<=s)
                    {
                        s=x;
                        if(c==0)
                        {
                            ii=a[i];
                            jj=a[j];
                        }
                        else
                        {
                            ii=a[j];
                            jj=a[i];
                        }
                    }
                }
            }
        }
        cout<<"Deepak should buy roses whose prices are "<<ii<<" and "<<jj<<"."<<endl;
    }
	return 0;
}
