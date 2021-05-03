/*
A subsequence is a sequence that can be derived from another sequence
by deleting some elements without changing the order of the remaining elements.
For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F},
obtained after removal of elements C, E and F.

Given two strings A and B of size n and m respectively,
you have to find the length of Longest Common Subsequence(LCS) of strings A and B,
where LCS is the longest sequence present in both A and B.

Input Format:
Two strings A and B.

Constraints:
1 <= n,m <= 10^3

Output Format:
Output the LCS of A and B.

Sample Input:
abc
acd
Sample Output:
2
*/
#include<iostream>
#include<cstring>
using namespace std;
int lcs(string a,string b)
{
    int n=a.length();
    int m=b.length();
    int arr[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            {
                arr[i][j]=0;
                continue;
            }
            if(a[i-1]==b[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[n][m];
}
int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout<<lcs(a,b);
	return 0;
}
