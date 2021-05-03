#include<iostream>
#include<map>
using namespace std;
int main()
{
    int a[10]={-1,2,-1,3,9,7};
    int sum=0,l=-1;
    map<int,int> m;
    for(int i=0;i<6;i++)
    {
        sum+=a[i];
        map<int,int>::iterator it=m.find(sum);
        if(m.find(sum)!=m.end())
        {
            if(l<(i-it->second))
            {
                l=i-it->second;
            }
        }
        else if(sum==0)
        {
            if(l<i)
            {
                l=i;
            }
        }
        else
        {
            m[sum]=i;
        }
    }
    cout<<l;
}
