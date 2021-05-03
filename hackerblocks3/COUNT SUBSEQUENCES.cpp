/*
COUNT SUBSEQUENCES
Given a string, count the number of distinct subsequences of it ( including empty subsequence ).
For the uninformed, A subsequence of a string is a new string which is formed
from the original string by deleting some of the characters without disturbing the
relative positions of the remaining characters. For example,
"AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

Input Format:
First line of input contains an integer 't' denoting number of test cases.
Each of next t lines contains a string s.

Constraints:
1<=t<=100
1<=length of s<=100000
s will contain upper letters only.

Output Format:
For each test case print ans%1000000007 where ans is the number of distinct subsequences.

Sample Input:
2
AAA
ABCDEFG
Sample Output:
4
128
Time Limit: 1 sec
*/
#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;
unordered_set<string> s;
void count(string a,int ai,char b[],int bi)
{
    if(a[ai]=='\0')
    {
        b[bi]='\0';
        //cout<<b<<"*";
        s.insert(b);
        return;
    }
    b[bi]=a[ai];
    //cout<<b[bi];
    count(a,ai+1,b,bi+1);
    count(a,ai+1,b,bi);
    return;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        string a;
        char b[100000];
        cin>>a;
        //cout<<a[2];
        //cout<<a;
        //cout<<b;
        count(a,0,b,0);
        cout<<s.size()<<endl;
        /*for(auto it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<endl;
        }*/
        s.clear();
    }
	return 0;
}
