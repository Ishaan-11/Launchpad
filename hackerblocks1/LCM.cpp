/*

Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Print the value returned.


Constraints:
0 < N1 < 1000000000
0 < N2 < 1000000000
Sample Input:
4
6
Sample Output:
12
Explanation:
The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.
*/
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,c,a,b,lcm,x,y;
    cin>>n1;
    cin>>n2;
    a=n1;
    b=n2;
    c=n2%n1;
    while(c!=0)
    {
        n2=n1;
        n1=c;
        c=n2%n1;
    }
    x=a/n1;
    y=b/n1;
    lcm=x*y*n1;
    cout<<lcm;
	return 0;
}
