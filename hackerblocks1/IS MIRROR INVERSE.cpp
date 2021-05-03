/*
Take the following as input.

A number
Assume that for a number of n digits, the value of each digit is from 1 to n and is unique.
E.g. 32145 is a valid input number.

Write a function which returns true if the number is mirror-inverse and false otherwise,
where inverse and mirror-inverse are defined as follows

Inverse of 32145 is 12543. In 32145, “5” is at 1st place,
therefore in 12543, “1” is at 5th place; in 32145, “4” is at 2nd place,
therefore in 12543, “2” is at 4th place.
A number is called mirror-inverse if its inverse is equal to itself. Print the value returned.

Input Format:
Integer

Constraints:
0 < N < 1000000000
Output Format:
Boolean

Sample Input:
12345
Sample Output:
true
Explanation:
Use functions. Write a function to get inverse and then use it check mirror-inverse property.
*/
#include<iostream>
using namespace std;
int main()
{
    char a[1000000000],b[1000000000];
    cin>>a;
    long long int i=0,l=0;
    while(a[i])
    {
        l++;
        i++;
    }
    for(i=0;i<l;i++)
    {
        int c=int(a[i]-'0');
        b[l-c]=(l-i)+'0';
    }
    b[l]='\0';
    for(i=0;i<l;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
	return 0;
}
