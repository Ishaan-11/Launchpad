/*
STRINGS-STRING COMPRESSION
Take as input S, a string.
Write a function that does basic string compression.
Print the value returned. E.g. for input “aaabbccds” print out a3b2c2ds.


Input Format:
A single String S.

Constraints:
A string of length between 1 to 1000
Output Format:
The compressed String.

Sample Input:
aaabbccds
Sample Output:
a3b2c2ds
Explanation:
In the given sample test case 'a' is repeated 3 times consecutively,
'b' is repeated twice, 'c' is repeated twice.
But, 'd' and 's' occurred only once that's why we do not write their occurrence.
*/
#include<iostream>
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    int count=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
        }
        else if(a[i]!=a[i+1])
        {
            cout<<a[i];
            if(count>0)
            {
                cout<<count+1;
            }
            count=0;
        }
    }
	return 0;
}
