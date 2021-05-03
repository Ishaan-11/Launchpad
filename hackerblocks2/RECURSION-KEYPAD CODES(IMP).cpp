/*
Take as input str, a string. str represents keys pressed on a nokia phone keypad.
We are concerned with all possible words that can be written with the pressed keys.

Assume the following alphabets on the keys:
1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 8 -> wx , 9 -> yz

E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”

a. Write a recursive function which returns the count of words for a given keypad string.
Print the value returned.

b.Write a recursive function which prints all possible words for a given
keypad string (void is the return type for function).

Input Format:
Enter a number

Constraints:
None
Output Format:
Display the total no. of words and display all the words in a space separated manner

Sample Input:
12
Sample Output:
9
ad ae af bd be bf cd ce cf
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
int count(char a[10][10],int i,char o[5])
{
    int c=0;
    if(a[0][i]=='\0')
    {
        return 1;
    }
    for(int x=0;a[a[0][i]-'0'][x]!='\0';x++)
    {
        o[i]=a[a[0][i]-'0'][x];
        o[i+1]='\0';
        c=c+count(a,i+1,o);
    }
    return c;
}
void print(char a[10][10],int i,char o[5])
{
    if(a[0][i]=='\0')
    {
        cout<<o<<" ";
        return;
    }
   // char t=a[0][i];
    for(int x=0;a[a[0][i]-'0'][x]!='\0';x++)
    {

        o[i]=a[a[0][i]-'0'][x];
        o[i+1]='\0';
        print(a,i+1,o);
    }
    return;
}
int main()
{
    char keypad[10][10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
    char o[5];
    cin>>keypad[0];
    cout<<count(keypad,0,o);
    cout<<endl;
    print(keypad,0,o);
	return 0;
}
