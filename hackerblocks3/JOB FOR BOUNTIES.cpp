/*
JOB FOR BOUNTIES
Mike’s boss gave him a string of opening and closing parenthesis asked him to find a
valid parenthesis substring in it.
He will get number of bounties equal to the length of substring he finds in return.
What is the maximum amount of number of bounties he can get?

Input Format:
The input file has a single line which contains a single string str that Mike's boss gave to him.

Constraints:
1 <= |str| <= 100000

Output Format:
Print, in a single line, the maximum amount of number of bounties Mike can get

Sample Input:
(()(()()
Sample Output:
4
Time Limit: 1 sec
*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
    char a[100000];
    cin>>a;
    stack<int> s;
    int dp[100000]={},ans=0;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='(')
        {
            s.push(i);
        }
        else if(!s.empty())
        {
            dp[i]=i-s.top()+1;
            if(s.top()>0)
            {
                dp[i]+=dp[s.top()-1];
            }
            ans=max(ans,dp[i]);
            s.pop();
        }
    }
    cout<<ans;
}
