/*

Take N (number of rows), print the following pattern (for N = 3).

                         1
                       2 3 2
                     3 4 5 4 3
                       2 3 2
                         1

Constraints:
0 < N < 10
Sample Input:
3
Sample Output:
                1
	2	3	2
3	4	5	4	3
	2	3	2
		1
Explanation:
Each number is separated from other by a tab.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" "<<"\t";
        }
        a=i;
        for(int j=0;j<i;j++)
        {
            cout<<a<<"\t";
            a++;
        }
        a=a-2;
        for(int k=1;k<i;k++)
        {
            cout<<a<<"\t";
            a--;
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++)
    {
         for(int j=1;j<=i;j++)
        {
            cout<<" "<<"\t";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<a<<"\t";
            a++;

        }
        a=a-2;
        for(int j=0;j<n-1-i;j++)
        {
            cout<<a<<"\t";
            a--;
        }
        cout<<endl;
    }
	return 0;
}
