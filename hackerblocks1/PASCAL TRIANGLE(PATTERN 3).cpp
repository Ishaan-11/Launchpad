/*

Take N (number of rows), print the following pattern (for N = 6)
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1


Constraints:
0 < N < 100
Sample Input:
6
Sample Output:
1
1	1
1	2	1
1	3	3	1
1	4	6	4	1
1	5	10	10	5	1
Explanation:
Each number is separated from other by a tab.
*/
#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    return fact(n-1)*n;
}
int ncr(int n,int r)
{
    return (fact(n)/(fact(n-r)*fact(r)));
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<ncr(i,j)<<'\t';
        }
        cout<<endl;
    }
	return 0;
}
