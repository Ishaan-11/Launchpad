#include<iostream>
using namespace std;
int main()
{
    int a[5]={};
    cout<<"enter elements of array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"reverse of array is: "<<endl;
    for(int i=4;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}

