#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int a1[10]={8,7,1,2,3};
    int a2[10]={9,5,2,8,3};
    unordered_set<int> s;
    for(int i=0;i<5;i++)
    {
        s.insert(a1[i]);
    }
    for(int i=0;i<5;i++)
    {
        unordered_set<int>::iterator it=s.find(a2[i]);
        if(it==s.end())
        {
            cout<<a2[i]<<"DOES NOT EXIST"<<endl;
        }
        if(it!=s.end())
        {
            cout<<a2[i]<<"EXIST"<<endl;
        }
    }
    return 0;
}
