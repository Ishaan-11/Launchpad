#include<iostream>
using namespace std;
int main()
{
    int a[5]={};
    cout<<"enter the elements of array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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
