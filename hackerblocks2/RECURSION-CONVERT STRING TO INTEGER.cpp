/*
Take as input str, a number in form of a string.
Write a recursive function to convert the number in string form to number in integer form.
E.g. for “1234” return 1234. Print the value returned.

Input Format:
Enter a number in form of a String

Constraints:
None
Output Format:
Print the number after converting it into integer

Sample Input:
1234
Sample Output:
1234
*/
#include<iostream>
#include<cstring>
using namespace std;
int power(int x,int y)
{
    int a=1;
    for(int i=1;i<=y;i++)
    {
        a=a*x;
    }
    return a;
}
int stoi(char a[100],int index)
{
    if(a[index]=='\0')
    {
        return 0;
    }
    int l=strlen(a);
    int x=stoi(a,index+1);
    int n=a[index]-'0';
    return x+n*(power(10,(l-1)-index));
}
int main()
{
    char a[100];
    cin>>a;
    cout<<stoi(a,0);
	return 0;
}
