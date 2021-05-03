#include<iostream>
using namespace std;
int main()
{
    int n,i=1;
    cout<<"enter a number: ";
    cin>>n;
    int a=n/2;
    while(i<=a)
    {
        int j=1;
        while(j<=(a+1)-i)
        {
            cout<<" "<<" ";
            j=j+1;
        }
        j=1;
        while(j<=(2*i)-1)
        {
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    i=1;
    while(i<=n-a)
    {
        int k=1;
        while(k<i)
        {
            cout<<" "<<" ";
            k=k+1;
        }
        int l=1;
        while(l<=(2*(n-a)+1)-2*i)
        {
            cout<<"*"<<" ";
            l=l+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}
