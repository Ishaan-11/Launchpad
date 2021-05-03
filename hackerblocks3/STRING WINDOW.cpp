 /*
Ravi has been given two strings named string1 and string 2.
He is supposed to find the minimum length substring of the string1 which
contains all the characters of string2. Help him to find the substring

Input Format:
The first line of the input contains string1. String1 can be a string containing spaces also.
The second line of the input contains string2. String2 can be a string containing spaces also.

Constraints:
Length of both the strings can be at max 10^4

Output Format:
Output the substring in a single line.
If no such substring exist then output "No string" without quotes

Sample Input:
qwerty asdfgh qazxsw
qas
Sample Output:
qazxs
Time Limit: 1 sec
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[10001],pat[10001];
    cin.getline(str,10001);
    cin.getline(pat,10001);
    int pat_freq[256]={0};
    int str_freq[256]={0};
    int lenS=strlen(str);
    int lenP=strlen(pat);
    for(int i=0;i<lenP;i++)
    {
        pat_freq[pat[i]]++;
    }
    int start=0,start_index=-1,min_length=10002,count=0;
    for(int i=0;i<lenS;i++)
    {
        str_freq[str[i]]++;
        if(pat_freq[str[i]]!=0 && str_freq[str[i]]<=pat_freq[str[i]])
        {
            count++;
        }
        if(count==lenP)
        {
            while(str_freq[str[start]]>pat_freq[str[start]] || pat_freq[str[start]]==0)
            {
                str_freq[str[start]]--;
                start++;
            }
            int len=i-start+1;
            if(len<min_length)
            {
                min_length=len;
                start_index=start;
            }
        }
    }
    if(start_index==-1)
    {
        cout<<"No string"<<endl;
    }
    else
    {
        for(int i=start_index;i<start_index+min_length;i++)
        {
            cout<<str[i];
        }
    }
	return 0;
}
