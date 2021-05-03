/*

Take N (number of rows), print the following pattern (for N = 4).

                       1           1
                       1 2       2 1
                       1 2 3   3 2 1
                       1 2 3 4 3 2 1

Constraints:
0 < N < 10
Sample Input:
4
Sample Output:
1						1
1	2				2	1
1	2	3		3	2	1
1	2	3	4	3	2	1
Explanation:
Each number is separated from other by a tab.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,j,k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j<<'\t';
        }
        for(j=1;j<=n-i;j++)
        {
            cout<<" "<<'\t';
        }
        for(k=1;k<=n-1-i;k++)
        {
            cout<<" "<<'\t';
        }
        for(j=1;j<=n-k;j++)
        {
            cout<<n-k-j+1<<'\t';
        }
        cout<<endl;
    }
	return 0;
}
