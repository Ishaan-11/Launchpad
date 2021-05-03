#include<iostream>
using namespace std;
int main()
{
    int a[5];
    int c=0;
    cout<<":enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
            cin>>a[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=i;j<5;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum=sum+a[k];
            }
            if(sum==0)
            {
                c++;
            }
        }
    }
    if(c==0)
    {
        cout<<"no substring with sum=0";
    }
    else
    {
        cout<<c<<" subarray with sum =0 found";
    }
    return 0;
}

