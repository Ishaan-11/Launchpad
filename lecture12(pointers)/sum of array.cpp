#include<iostream>
using namespace std;
int sum(int *a,int n)
{
    int sum=0;
    //for(int i=0;i<n-2;i++)
    for(int i=0;i<n;i++)
    {
        sum+=*(a+i);
    }
    return sum;
}
int main()
{
    int a[5];
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>*(a+i);
    }
    //cout<<sum(a+2,5);
    cout<<sum(a,5);
    return 0;
}
