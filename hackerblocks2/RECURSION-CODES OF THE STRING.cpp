/*
Take as input str, a string.
Assume that value of a=1, b=2, c=3, d=4, …. z=26.
Write a recursive function (return type Arraylist) to print all possible codes for the string.
E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format:
Enter a number

Constraints:
None

Output Format:
Display all the possible codes

Sample Input:
1125
Sample Output:
[aabe, aay, ale, kbe, ky]
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
void sub(char in[],int i,char out[],int o)
{
    static int c=0;
    if(in[i]=='\0')
    {
        out[o]='\0';
        if(c==0)
        {
            c++;
            cout<<out;
        }
        else
        {
            cout<<", "<<out;
        }
        return;
    }
    out[o]=in[i]-'0'+96;
    sub(in,i+1,out,o+1);
    if(in[i+1]!='\0' && in[i+1]-'0'<=6 && in[i]-'0'<=2)
    {
        int number=(in[i]-'0')*10+(in[i+1]-'0');
        out[o]=number+96;
        sub(in,i+2,out,o+1);
    }
}
int main()
{
    char in[100000];
    char out[100000];
    cin>>in;
    cout<<"[";
    sub(in,0,out,0);
    cout<<"]";
	return 0;
}
