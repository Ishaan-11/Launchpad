#include<iostream>
using namespace std;
int main()
{
    int a[10],start=0,end=10-1;
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<10;i++)
    {
            cin>>a[i];
    }
    while(start<end)
    {
        if(a[start]==0)
        {
            for(int k=0;k<end-start;k++)
            {
                a[start+k]=a[start+1+k];
            }
            a[end]=0;
            end--;
        }
        else
        {
            start++;
        }
    }
    cout<<"array becomes"<<endl;
    for(int i=0;i<10;i++)
    {
            cout<<a[i];
    }
    return 0;
}

