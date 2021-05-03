/*
Check for duplicate parenthesis in an expression

Input Format:
First line contains T, the number of testcases.
Then each testcase contains a string in which we check for duplicacy.

Constraints:
1<=T<=100
10<=len(str)<=1000
Output Format:
For each testcase print "Duplicate Found" if we have duplicacy
otherwise print "No Duplicates Found" if there are no duplicates.

Sample Input:
2
(((a+(b))+(c+d)))
((a+b)+(c+d))
Sample Output:
Duplicate Found
No Duplicates Found
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char>s;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        char a[1000];
        cin>>a;
        int k=0;
        for(int j=0;a[j]!='\0';j++)
        {
            if(a[j]==')')
            {
                char top=s.top();
                s.pop();
                int x=0;
                while(top!='(')
                {
                    x++;
                    top=s.top();
                    s.pop();
                }
                if(x==0)
                {
                    k=1;
                    cout<<"Duplicate Found"<<endl;
                    break;
                }
            }
            else
            {
                s.push(a[j]);
            }
        }
        if(k==0)
        {
            cout<<"No Duplicates Found"<<endl;
        }
    }
	return 0;
}
