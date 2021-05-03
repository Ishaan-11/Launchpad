#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int a[10]={5,7,-1,-5,-7};
    unordered_set<int> s;
    for(int i=0;i<5;i++)
    {
        if(s.find(-a[i])!=s.end())
        {
            cout<<a[i]<<" "<<-a[i]<<endl;
            s.erase(-a[i]);
        }
        else
        {
            s.insert(a[i]);
        }
    }
    return 0;
}
