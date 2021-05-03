/*
Take the following as input.

A number (X)
A number (N)
Write a function which returns Log of X to the base N. Print the value returned.


Constraints:
0 < X < 1000000000
0 < N < 1000
Sample Input:
1000
10
Sample Output:
3
Explanation:
Assume that X and N are such that Log of X to the base N will be a whole number.
*/
#include<iostream>
using namespace std;
int main()
{
    int x,n,a=0;
    cin>>x;
    cin>>n;
    while(x>1)
    {
        a++;
        x=x/n;
    }
    cout<<a;
	return 0;
}
