/*

Take as input S, a string.
Write a function that replaces every odd character with the character having just higher ascii code
and every even character with the character having just lower ascii code. Print the value returned.


Input Format:
String

Constraints:
Length of string should be between 1 to 1000.
Output Format:
String

Sample Input:
abcg
Sample Output:
badf
*/
#include<iostream>
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    for(int i=0;a[i]!='\0';i++)
    {
        if(i%2==0)
        {
            a[i]=char(a[i]+1);
        }
        else
        {
            a[i]=char(a[i]-1);
        }
    }
    cout<<a;
	return 0;
}
