#include<iostream>
using namespace std;
void f(int *arr,int n)
{
    cout<<sizeof(arr)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<endl;
    }
    return;
}
void f1(int arr[10],int n)
{
    cout<<sizeof(arr)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<endl;
    }
    return;
}
void f2(int *arr,int n)
{
    cout<<sizeof(arr)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return;
}
int main()
{
    int arr[10]={1,2,3};
    cout<<sizeof(arr)<<endl;
    f(arr,3);
    cout<<endl;
    f1(arr,3);
    cout<<endl;
    f2(arr,3);
    cout<<endl;
    return 0;
}
