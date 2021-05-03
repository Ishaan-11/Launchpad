/*
Take the following as input.

A number (N)
Take N more numerical inputs
The N inputs for a sequence S = s1, s2, .., sN.
Compute if it is possible to split sequence into two sequences -
s1 to si and si+1 to sN such that first sequence is strictly decreasing
and second is strictly increasing. Print true/false as output.

Constraints:
0 < N < 1000
Each number in sequence S is > 0 and < 1000000000
Sample Input:
5
1
2
3
4
5
Sample Output:
true
Explanation:
Carefully read the conditions to judge which all sequences may be valid. Don't use arrays or lists.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,s,s1,c=0;
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        cin>>s1;
        if(c==0 && s==s1)
        {
            cout<<"false";
            return 0;
        }
        if(c==0 || c==2)
        {
            if(s>s1)
            {
                c=2;
            }
            else//else if(s<s1)
            {
                c=1;
            }
        }
        else if(c==0||c==1)
        {
            if(s<s1)
            {
                c=1;
            }
            else
            {
                cout<<"false";
                return 0;
            }
        }
        s=s1;
    }
    cout<<"true";
	return 0;
}
