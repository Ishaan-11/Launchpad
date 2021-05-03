#include<iostream>
using namespace std;
int sum(int a[10],int n,int index)
{
    if(index==n-1)
    {
        return a[index];
    }
    int right =sum(a,n,index+1);
    return a[index]+right;
}
int main()
{
    int a[10];
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"sum of array is "<<sum(a,5,0);
    return 0;
}
