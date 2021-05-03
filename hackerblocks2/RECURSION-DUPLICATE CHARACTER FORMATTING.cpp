/*
Take as input str, a string.
Write a recursive function which returns a new string in which all duplicate
consecutive characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”.
Print the value returned

Input Format:
Enter a String

Constraints:
None
Output Format:
Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

Sample Input:
hello
Sample Output:
hel*lo
*/
#include<iostream>
#include<cstring>
using namespace std;
void dup(char a[100], int i)
{
    if(a[i]=='\0')
    {
        return;
    }
    int l=strlen(a);
    if(a[i]==a[i+1])
    {
        for(int k=0;k<l-i;k++)
        {
            a[l+1-k]=a[l-k];
        }
        a[i+1]='*';
    }
    dup(a,i+1);
    return;
}
int main()
{
    char a[100];
    cin>>a;
    dup(a,0);
    cout<<a;
	return 0;
}
