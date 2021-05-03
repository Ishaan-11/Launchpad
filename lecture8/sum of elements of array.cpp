#include<iostream>
using namespace std;
int sum_array(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int a[5];
    cout<<"enter elements of array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"sum is: "<<sum_array(a,5);
    return 0;
}
