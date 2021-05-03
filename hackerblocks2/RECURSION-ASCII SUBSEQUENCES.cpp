/*
RECURSION-ASCII SUBSEQUENCES
Take as input str, a string. We are concerned with all the possible ascii-subsequences of str.
E.g. “ab” has following ascii-subsequences “”, “b”, “98”, “a”, “ab”, “a98”, “97”, “97b”, “9798”

a. Write a recursive function which returns the count of ascii-subsequences for a given string.
Print the value returned.

b. Write a recursive function which prints all possible ascii-subsequences
for a given string (void is the return type for function).

Input Format:
Enter the string

Constraints:
None

Output Format:
Display the number of ASCII-subsequences and display all the ASCII- subsequences

Sample Input:
ab
Sample Output:
9
 b 98 a ab a98 97 97b 9798
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
int count(char a[],int i)
{
    if(a[i]=='\0')
    {
        return 1;
    }
    int c=0;
    c+=count(a,i+1);
    c+=count(a,i+1);
    c+=count(a,i+1);
    return c;

}
void ascii(char a[],int i,char b[],int j)
{
    if(a[i]=='\0')
    {
        b[j]='\0';
        cout<<b<<" ";
        return;
    }
    ascii(a,i+1,b,j);
    b[j]=a[i];
    ascii(a,i+1,b,j+1);
    int x=int(a[i]);
    b[j+1]=x%10+48;
    b[j]=x/10+48;
    ascii(a,i+1,b,j+2);
    return;
}
int main()
{
    char a[100],b[100];
    cin>>a;
    cout<<count(a,0)<<endl;
    ascii(a,0,b,0);
	return 0;
}
