/*
Take N as input. Print Nth Fibonacci Number,
given that the first two numbers in the Fibonacci Series are 0 and 1.


Constraints:
0 <= N <= 1000
Sample Input:
10
Sample Output:
55
Explanation:
The 0th fibonnaci is 0 and 1st fibonnaci is 1.
*/
#include <iostream>
using namespace std;
int main()
{
    int n,i=3;
    cin>>n;
    int a=0,b=1;
    int c=a+b;
    while(i<=n)
    {
        a=b;
        b=c;
        c=a+b;
        i++;
    }
    if(n==0)
    {
        cout<<a;
    }
    else if(n==1)
    {
        cout<<b;
    }
    else
    {
        cout<<c;
    }
   return 0;
}
