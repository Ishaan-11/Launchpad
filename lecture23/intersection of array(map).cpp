#include<iostream>
#include<map>
using namespace std;
int main()
{
    int a1[10]={1,7,3,5,4,3,3};
    int a2[10]={7,3,5,3,6,3,3};
    map<int,int> m;
    for(int i=0;i<7;i++)
    {
        if(m.find(a1[i])!=m.end())
        {
            m[a1[i]]++;
        }
        else
        {
            m[a1[i]]=1;
        }
    }
    for(int i=0;i<7;i++)
    {
        if(m.find(a2[i])!=m.end()&& m[a2[i]]>0)
        {
            m[a2[i]]--;
            cout<<a2[i]<<" ";
        }
    }
    return 0;
}
