/*

Take as input S, a string.
Write a function that returns the character with maximum frequency.
Print the value returned.


Input Format:
String

Constraints:
A string of length between 1 to 1000.
Output Format:
Character

Sample Input:
aaabacb
Sample Output:
a
Explanation:
For the given input string, a appear 4 times. Hence, it is the most frequent character.
*/
#include<iostream>
#include<climits>
using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    int ascii[256]={0},max=INT_MIN,max_index;
    for(int i=0;a[i]!='\0';i++)
    {
        ascii[a[i]]++;
    }
    for(int i=0;i<256;i++)
    {
        if(ascii[i]>max)
        {
            max=ascii[i];
            max_index=i;
        }
    }
    cout<<char(max_index);
	return 0;
}
