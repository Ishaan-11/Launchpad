/*
Take as input x and n, two numbers.
Write a function to calculate x raise to power n. Target complexity is O(logn).
NOTE: Try both recursive and bitmasking approach.

Input Format:
Enter the number N and its power P

Constraints:
None
Output Format:
Display N^P

Sample Input:
2
3
Sample Output:
8
*/
#include<iostream>
using namespace std;
int pow(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    return (x*pow(x,n-1));
}
int main()
{
    int n,x;
    cin>>x;
    cin>>n;
    cout<<pow(x,n);
	return 0;
}
