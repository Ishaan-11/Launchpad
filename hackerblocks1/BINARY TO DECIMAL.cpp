/*

Take N (number in binary format). Write a function that converts it to decimal format and Print the value returned.


Constraints:
0 < N <= 1000000000
Sample Input:
101010
Sample Output:
42
Explanation:
For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,c=0,b=0,a;
    cin>>n;
    while(n>0)
    {
        int sum=1;
        c++;
        a=n%10;
        for(int i=1;i<c;i++)
        {
            sum =sum*2;
        }
        b=b+sum*a;
        n=n/10;
    }
    cout<<b;
	return 0;
}
