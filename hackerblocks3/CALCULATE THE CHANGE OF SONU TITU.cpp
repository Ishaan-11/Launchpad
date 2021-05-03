/*
Sonu and Titu have two Strings. They want to make their strings anagrams of each other.
They can either delete a character from string of Titu and add a character to the string of Sonu.
Find the minimum number of operations required to make the strings anagrams of each other.

Input Format:
First line of input contains number of test cases T. Each test case contains two lines.
First line contains string of Sonu and second line contains string of Titu.

Constraints:
0 <= N <= 10
Length of each string <= 10^5

Output Format:
For each test case print the minimum number of operations required in a new line.

Sample Input:
1
abde
edg
Sample Output:
3
Time Limit: 2 sec
*/
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        string a,b;
        map<char,int> s;
        map<char,int> a1;
        cin>>a;
        cin>>b;
        for(int i=0;i<a.length();i++)
        {
            s[a[i]]++;
            a1[a[i]]++;
        }
        for(int i=0;i<b.length();i++)
        {
            if(a1.find(b[i])!=a1.end())
            {
                s[b[i]]--;
                a1[b[i]]--;
                if(a1[b[i]]<=0)
                {
                    a1.erase(b[i]);
                }
            }
            else
            {
                s[b[i]]++;
            }
        }
        int count=0;
        for(auto it=s.begin();it!=s.end();it++)
        {
            if(it->second>0)
            {
                count+=it->second;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}
/*better
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int T;
    cin>>T;
    cin.get();
    for(int t=0;t<T;t++)
    {
        char a[100001];
        char b[100001];
        cin.getline(a,100001);
        cin.getline(b,100001);
        map<char,int>m;
        int freq[256]={0};
        for(int i=0;a[i]!='\0';i++)
        {
            m[a[i]]++;
            freq[a[i]]++;
        }
        for(int i=0;b[i]!='\0';i++)
        {
            if(freq[b[i]]>0)
            {
                freq[b[i]]--;
                m[b[i]]--;
            }
            else
            {
                m[b[i]]++;
            }
        }
        map<char,int>::iterator it;
        int c=0;
        for(it=m.begin();it!=m.end();it++)
        {
            c+=it->second;
        }
        cout<<c<<endl;
    }
	return 0;
}
*/
