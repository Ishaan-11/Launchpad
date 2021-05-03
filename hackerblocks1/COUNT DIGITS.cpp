/*

Take the following as input.
A number
A digit
Write a function that returns the number of times digit is found in the number. Print the value returned.


Input Format:
Integer (A number) Integer (A digit)

Constraints:
0 <= N <= 1000000000
0 <= Digit <= 9
Output Format:
Integer (count of times digit occurs in the number)

Sample Input:
5433231
3
Sample Output:
3
Explanation:
The digit can be from 0 to 9. Assume decimal numbers
*/
#include<iostream>
using namespace std;
int main()
{
    int n,x,c=0;
    cin>>n;
    cin>>x;
    while(n>0)
    {
        int a=n%10;
        if(a==x)
        {
            c++;
        }
        n=n/10;
    }
    cout<<c;
	return 0;
}
