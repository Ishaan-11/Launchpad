#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int> m;
    int a[10]={3,2,1,3,4,1};
    //m[0]=a[0];
    for(int i=0;i<6;i++)
    {
        //map<int,int>::iterator it=m.find(i);
        if(m.find(a[i])==m.end())
        {
            m[a[i]]=i;
            //break;
        }
    }
    map<int,int>::iterator it;
    //int i=0;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->first;
            //i++;
    }
    /*for(int j=0;j<i;j++)
    {
        cout<<a[i]<<" ";
    }*/
}

