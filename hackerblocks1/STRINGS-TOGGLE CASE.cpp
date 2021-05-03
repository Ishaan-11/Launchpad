/*

Take as input S, a string. Write a function that toggles the case of all characters in the string.
Print the value returned.


Input Format:
String

Constraints:
Length of string should be between 1 to 1000.
Output Format:
String

Sample Input:
abC
Sample Output:
ABc
Explanation:
Toggle Case means to change UpperCase character to LowerCase character and vice-versa.
*/
#include<iostream>
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            a[i]=a[i]-32;
        }
        else
        {
            a[i]=a[i]+32;
        }
    }
    cout<<a;
	return 0;
}
