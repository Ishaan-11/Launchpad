/*

Take as input N, a number. Print the pattern like this.

for N = 5

5

3

1

2

4


Input Format:
Number

Constraints:
1 <= N <= 100
Output Format:
Pattern

Sample Input:
10
Sample Output:
9

7

5

3

1

2

4

6

8

10

*/
#include<iostream>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    a=n/2;
    if(n%2==0)
    {
        int x=n-1;
        for(int j=a;j>0;j--)
        {
            cout<<x;
            x=x-2;
            cout<<endl;
        }
        int y=2;
        for(int j=1;j<=n-a;j++)
        {
            cout<<y;
            y=y+2;
            cout<<endl;
        }
    }
    else
    {
        int x=n;
        for(int j=a;j>=0;j--)
        {
            cout<<x;
            x=x-2;
            cout<<endl;
        }
        int y=2;
        for(int j=1;j<n-a;j++)
        {
            cout<<y;
            y=y+2;
            cout<<endl;
        }
    }
	return 0;
}
