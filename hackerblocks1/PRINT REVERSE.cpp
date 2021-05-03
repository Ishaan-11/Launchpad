/*

Take N as input, Calculate it's reverse also Print the reverse.


Constraints:
0 <= N <= 1000000000
Sample Input:
123456789
Sample Output:
987654321
Explanation:
You've to calculate the reverse in a number, not just print the reverse.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a,b=0;
    cin>>n;
    while(n>0)
    {
        a=n%10;
        b=b*10+a;
        n=n/10;
    }
    cout<<b;
	return 0;
}
