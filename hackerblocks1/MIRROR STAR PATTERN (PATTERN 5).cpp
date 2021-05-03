/*

Take N (number of rows - only odd numbers allowed), print the following pattern (for N = 5).

      *
   *  *  *
*  *  *  *  *
   *  *  *
      *

Constraints:
0 < N < 10 (only odd numbers allowed)
Sample Input:
5
Sample Output:
      *
    * * *
  * * * * *
    * * *
      *
Explanation:
Each '*' is separated from other by a tab.
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=n/2;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=a+1-i;j++)
        {
            cout<<" "<<'\t';
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<'\t';
        }
        for(int j=1;j<=i-1;j++)
        {
            cout<<"*"<<'\t';
        }
        cout<<endl;
    }
    for(int i=1;i<=n-a;i++)
    {
        for(int j=1;j<i;j++)
        {
        cout<<" "<<'\t';
        }
        for(int j=1;j<=n-a+1-i;j++)
        {
            cout<<"*"<<'\t';
        }
        for(int j=1;j<=n-a-i;j++)
        {
            cout<<"*"<<'\t';
        }
        cout<<endl;
    }
	return 0;
}
