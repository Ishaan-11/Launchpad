/*
Take N (number in decimal format). Write a function that converts it to octal format.
Print the value returned.

Constraints:
0 < N <= 1000000000
Sample Input:
63
Sample Output:
77
Explanation:
Both input and output are integers
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a,b=0,i=1;
    cin>>n;
    while(n>0)
    {
        a=n%8;
        b=b+a*i;
        i=i*10;
        n=n/8;
    }
    cout<<b;
	return 0;
}
