/*
Print all the subsequences of a string in lexicographical order.

Input Format:
First line contains an integer N, the no of strings.
Next, N lines follows one string per line.

Constraints:
1 < len(str) < 20
Output Format:
No of subsequences one per line

Sample Input:
1
ab
Sample Output:

a
ab
b
Explanation:
4 subsequences are printed.
Empty string is a subsequence.
*/
#include<iostream>
#include<set>
using namespace std;
set<string> s;
void sub(char i[20],int i_index,char o[20],int o_index)
{
    if(i[i_index]=='\0')
    {
        for(int i=0;i<o_index;i++)
        {
            //cout<<o[i];
        }
        o[o_index]='\0';
        s.insert(o);
        //cout<<endl;
        return;
    }
    o[o_index]=i[i_index];
    sub(i,i_index+1,o,o_index+1);
    sub(i,i_index+1,o,o_index);
    return;
}
int main()
{
    char i[20],o[20];
    int n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        cin>>i;
        sub(i,0,o,0);
        set<string>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<endl;
        }
        s.clear();
    }
	return 0;
}
