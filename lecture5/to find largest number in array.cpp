#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int a[10]={};
    cout<<"enter elements in array: "<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    int max=INT_MIN;
    for(int i=0;i<10;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    cout<<"the maximum element in array is: "<<max;
    return 0;
}

