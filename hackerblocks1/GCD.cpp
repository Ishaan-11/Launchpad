/*

Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the GCD of N1 and N2. Print the value returned.


Constraints:
0 < N1 < 1000000000
0 < N2 < 1000000000
Sample Input:
16
24
Sample Output:
8
Explanation:
The largest number that divides both N1 and N2 is called the GCD of N1 and N2.
*/
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,c;
    cin>>n1;
    cin>>n2;
    c=n2%n1;
    while(c!=0)
    {
        n2=n1;
        n1=c;
        c=n2%n1;
    }
    cout<<n1;
	return 0;
}
