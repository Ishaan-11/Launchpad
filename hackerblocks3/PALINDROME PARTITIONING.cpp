/*
PALINDROME PARTITIONING
You are given a string.
You need to partition that string such that each substrings after partitioning would be
palindromic string. You have to do this work with minimum number of partitioning.

Input Format:
First line contains integer t which is number of test case.
For each test case, it contains a string S.

Constraints:
1<=t<=50
1<=S<=1000

Output Format:
Print the minimum number of partitioning.

Sample Input:
1
ababbbabbababa
Sample Output:
3
Explanation:
a|babbbab|b|ababa
*/
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int part(char* a,int n)
{
    int c[1001];
    bool p[1001][1001];
    int i,j,k,l;
    for(i=0;i<n;i++)
    {
        p[i][i]=true;
    }
    for(l=2;l<n;l++)
    {
        for(i=0;i<n-l;i++)
        {
            j=i+l-1;
            if(l==2)
            {
                p[i][j]=(a[i]==a[j]);
            }
            else
            {
                p[i][j]=((a[i]==a[j]) && p[i+1][j-1]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(p[0][i]==true)
        {
            c[i]=0;
        }
        else
        {
            c[i]=INT_MAX;
            for(j=0;j<i;j++)
            {
                if(p[j+1][i]==true && 1+c[j]<c[i])
                {
                    c[i]=1+c[j];
                }
            }
        }
    }
    return c[n-1];
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        char a[1001];
        cin>>a;
        int l=strlen(a);
        cout<<part(a,l)<<endl;
    }
	return 0;
}
