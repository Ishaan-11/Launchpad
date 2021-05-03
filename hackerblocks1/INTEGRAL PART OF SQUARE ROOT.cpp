/*

Take the following as input.

A number (N)
Write a function which returns the integral part of square root of N. Print the value returned.


Constraints:
0 < N < 1000000000
Sample Input:
37
Sample Output:
6
Explanation:
Just print the integral part of square root of number.
*/
#include<iostream>
using namespace std;
int main()
{
    int i=0;int a,n;
    cin>>n;
    while(i*i<=n)
    {
        a=i;
        i++;
    }
    cout<<a;
	return 0;
}
