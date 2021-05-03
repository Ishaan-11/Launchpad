/*

Take the following as input.

A number
Write a function which returns true if the number is an armstrong number and false otherwise,
where armstrong number is defined as follows

371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3
Print the value returned.


Input Format:
Integer

Constraints:
0 < N < 1000000000
Output Format:
Boolean

Sample Input:
371
Sample Output:
true
Explanation:
Use functions. Write a function to get check if the number is armstrong number or not.
Numbers are armstrong if it is equal to sum of each digit raised to the power of number of digits.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a,b=0;
    cin>>n;
    int x=n;
    while(n>0)
    {
        a=n%10;
        b=b+a*a*a;
        n=n/10;
    }
    if(b==x)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
	return 0;
}
