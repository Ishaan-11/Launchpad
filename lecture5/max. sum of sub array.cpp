#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int max=INT_MIN;
    int arr[5]={};
    cout<<"enter elemnets of array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=i;j<5;j++)
        {
            int a=0;
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
                a=a+arr[k];
            }
            if(a>max)
            {
                max=a;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"max. sum of sub array: "<<max;
    return 0;
}
