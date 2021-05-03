/*
ARRAYS-SUM OF TWO ARRAYS
Take as input N, the size of array.
Take N more inputs and store that in an array.
Take as input M, the size of second array and take M more inputs and store that in second array.
Write a function that returns the sum of two arrays. Print the value returned.

Constraints:
Length of Array should be between 1 and 1000.

Sample Input:
4
1 0 2 9
5
3 4 5 6 7
Sample Output:
3, 5, 5, 9, 6, END
Explanation:
Sum of [1, 0, 2, 9] and [3, 4, 5, 6, 7] is [3, 5, 5, 9, 6] and the first digit represents carry over ,
if any (0 here ) .
*/
#include<iostream>
using namespace std;
void print(int n)
{
    if(n==0)
    {
        return;
    }
    int x=n%10;
    print(n/10);
    cout<<x<<", ";
    return;
}
int main()
{
    int n1,n2,a[1000],b[1000],A=0,B=0;
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
        A=A*10+a[i];
    }
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cin>>b[i];
        B=B*10+b[i];
    }
    print(A+B);
    cout<<"END";
	return 0;
}
