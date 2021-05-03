/*
Take as input S, a string.
Write a program that gives the count of substrings of this string which are palindromes and Print the ans.


Input Format:
String

Constraints:
Length of string is between 1 to 1000.
Output Format:
Integer

Sample Input:
abc
Sample Output:
3
Explanation:
For the given sample case ,
the palindromic substrings of the string abc are "a","b" and "c".So, the ans is 3.
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
        for(int j=i;a[j]!='\0';j++)
        {
                int start=i,end=j,c=1;
                while(start<end)
                {
                    if(a[start]!=a[end])
                    {
                        c=0;
                    }
                    start++;
                    end--;
                }
                if(c==1)
                {
                    count++;
                }
        }
    }
    cout<<count;
	return 0;
}
