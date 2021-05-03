#include<iostream>
using namespace std;
int main()
{
    int a[10],x;
    cout<<"enter the elements of array: "<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the value of x: ";
    cin>>x;
    cout<<"the triplets of array which sum to "<<x<<" are: "<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            for(int k=j+1;k<10;k++)
            {
                if((a[i]+a[j]+a[k])==x)
                {
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                }
            }
        }
    }
    return 0;
}

