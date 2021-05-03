/*

Take N (number of rows), print the following pattern (for N = 5).

     * * * * *
     * *   * *
     *       *
     * *   * *
     * * * * *

Constraints:
0 < N < 10 (where N is an odd number)
Sample Input:
5
Sample Output:
*	*	*       *      *
*	*	        *      *
* 	                       *
* 	*               *      *
* 	*	*       *      *
Explanation:
Each '*' is separated from other by a tab.

Time Limit: 2 sec
*/
#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    int a=n/2;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=a+2-i;j++)
        {
            cout<<"*"<<"\t";
        }
        for(int j=1;j<i;j++)
        {
            cout<<" "<<"\t";
        }
        for(k=2;k<i;k++)
        {
            cout<<" "<<"\t";
        }
        for(int j=1;j<=a+2-k;j++)
        {
            cout<<"*"<<"\t";
        }
        cout<<endl;
    }
    for(int i=1;i<=n-a;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<"\t";
        }
        for(int j=1;j<=(n-a)-i;j++)
        {
            cout<<" "<<"\t";
        }
        for(k=1;k<=(n-a)-i-1;k++)
        {
            cout<<" "<<"\t";
        }
        for(int j=1;j<=(n-a)-k;j++)
        {
            cout<<"*"<<"\t";
        }
        cout<<endl;
    }
}
