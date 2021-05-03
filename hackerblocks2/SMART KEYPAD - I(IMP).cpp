/*
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format:
A single string containing numbers only.

Constraints:
length of string <= 10
Output Format:
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input:
12
Sample Output:
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
Explanation:
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.
*/
#include<iostream>
using namespace std;
void print(char a[11][11],int i,char o[11])
{
    if(a[10][i]=='\0')
    {
        cout<<o<<endl;
        return;
    }
    for(int x=0;a[a[10][i]-'0'][x]!='\0';x++)
    {
        o[i]=a[a[10][i]-'0'][x];
        o[i+1]='\0';
        print(a,i+1,o);
    }
    return;
}
int main()
{
    char keypad[11][11]={" ",".+@$","abc","def","ghi","jkl",
                            "mno", "pqrs" , "tuv", "wxyz" };
    char o[11];
    cin>>keypad[10];
    print(keypad,0,o);
	return 0;
}
/*
#include<iostream>
using namespace std;
char table[][5] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void keypad(char a[],int i,char b[],int j)
{
    if(a[i]=='\0')
    {
        b[j]='\0';
        cout<<b<<endl;
        return;
    }
    for(int x=0;table[a[i]-48][x]!='\0';x++)
    {
        b[j]=table[a[i]-48][x];
        keypad(a,i+1,b,j+1);
    }
    //keypad(a,i+1,b,j);
    return;
}
int main()
{
    char a[100],b[100];
    cin>>a;
    keypad(a,0,b,0);
	return 0;
}
*/
