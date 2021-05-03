#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int a[5],b[5];
    cout<<"enter elements of first array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"enter elements of second array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>b[i];
    }
    int x=INT_MIN;
    cout<<"intersection of given array: "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i]==b[j])
            {
                if(x!=a[i])
                {
                    cout<<a[i]<<" ";
                }
                x=a[i];
                break;
            }
        }
    }
    return 0;
}
