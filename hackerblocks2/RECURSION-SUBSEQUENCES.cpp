/*
Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

a. Write a recursive function which returns the count of subsequences for a given string.
Print the value returned.

b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences
“”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.
given string (void is the return type for function).

Input Format:
Enter a string

Constraints:
None
Output Format:
Display the total no. of subsequences and also print all the subsequences in a space separated manner

Sample Input:
abcd
Sample Output:
16
 d c cd b bd bc bcd a ad ac acd ab abd abc abcd
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
int count_sub(char i[1000],int i_ind,char o[1000],int o_ind)
{
    int count=0;
    o[o_ind]=i[i_ind];
    if(i[i_ind]=='\0')
    {
        return 1;
    }
    count+=count_sub(i,i_ind+1,o,o_ind+1);
    count+=count_sub(i,i_ind+1,o,o_ind);
    return count;
}
void sub(char i[1000],int i_ind,char o[1000],int o_ind)
{
    o[o_ind]=i[i_ind];
    if(i[i_ind]=='\0')
    {
        cout<<o<<" ";
        return;
    }
    sub(i,i_ind+1,o,o_ind);
    o[o_ind]=i[i_ind];
    sub(i,i_ind+1,o,o_ind+1);
    o[o_ind]=i[i_ind];
    return;
}
int main()
{
    char i[1000],o[1000];
    cin>>i;
    cout<<count_sub(i,0,o,0);
    cout<<endl;
    sub(i,0,o,0);
	return 0;
}
