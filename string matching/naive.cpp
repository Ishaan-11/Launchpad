#include<iostream>
#include<string>
using namespace std;
void naive(string str,string pat)
{
    for(int i=0;i<=str.size()-pat.size();i++)
    {
        int j;
        for(j=0;j<pat.size();j++)
        {
            if(str[i+j]!=pat[j])
            {
                break;
            }
        }
        if(j==pat.size())
        {
            cout<<"pattern found at "<<i<<endl;
        }
    }
    return;
}
int main()
{
    string str,pat;
    cin>>str>>pat;
    naive(str,pat);
    return 0;
}
/*
aabaacaadaabaaabaa
aaba
*/
