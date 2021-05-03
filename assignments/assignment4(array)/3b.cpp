#include<iostream>
using namespace std;
int main()
{
    int a[5]={},temp;
    cout<<"enter elements in array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[j]>a[i])
            {
                temp=a[i];
                for(int k=0;k<i-j;k++)
                {
                    a[i-k]=a[i-k-1];
                }
                a[j]=temp;
                break;
            }
        }
    }
    cout<<"array after sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i];
    }
    return 0;
}

