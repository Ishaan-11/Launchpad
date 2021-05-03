/*

Take as input S, a string. Write a function that removes all consecutive duplicates.
Print the value returned.


Input Format:
String

Constraints:
A string of length between 1 to 1000
Output Format:
String

Sample Input:
aabccba
Sample Output:
abcba
Explanation:
For the given example, "aabccba", Consecutive Occurrence of a is 2, b is 1, and c is 2.

After removing all of the consecutive occurences, the Final ans will be : - "abcba".
*/
#include<iostream>
#include<cstring>
using namespace std;
void dup(char a[100],int i)
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
            a[i+k]=a[i+1+k];
        }
    }
    if(a[i]==a[i+1])
    {
        dup(a,i);
    }
    dup(a,i+1);
    return;
}
int main()
{
    char a[100];
    cin.getline(a,100);
    dup(a,0);
    cout<<a;
	return 0;
}
