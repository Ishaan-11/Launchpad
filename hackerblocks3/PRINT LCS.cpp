/*
A subsequence is a sequence that can be derived from another sequence by
deleting some elements without changing the order of the remaining elements.
For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F},
obtained after removal of elements C, E and F.

Given two strings A and B of size n and m respectively,
you have to print the Longest Common Subsequence(LCS) of strings A and B,
where LCS is the longest sequence present in both A and B.

Note: It is gauranteed that there is only one unique longest common subsequence

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
ac
*/
#include<iostream>
#include<cstring>
using namespace std;
void lcs(string a,string b)
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
    int l=arr[n][m];//length of lcs
    char A[l+1];
    A[l]='\0';
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            A[l-1]=a[i-1];
            i--;j--;l--;
        }
        else if(arr[i-1][j]>arr[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<A;
}
int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    lcs(a,b);
	return 0;
}
