#include<iostream>
using namespace std;
int main()
{
    int i=1,n,a;
    cout<<" enter a number: ";
    cin>>n;
    a=n/2;
    while(i<=a)
    {
//first part of program
        int j=1;
        while(j<=a+2-i)
        {
            cout<<"*"<<" ";
            j=j+1;
        }
        j=1;
        while(j<i)
        {
            cout<<" "<<" ";
            j=j+1;
        }
//second part of program
        int k=2;
        while(k<i)
        {
            cout<<" "<<" ";
            k=k+1;
        }
        j=1;
        while(j<=(a+2)-k)
        {
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    i=1;
    while(i<=(n-a))
    {
//third part of program
        int j=1;
        while(j<=i)
        {
            cout<<"*"<<" ";
            j=j+1;
        }
        j=1;
        while(j<=(n-a)-i)
        {
            cout<<" "<<" ";
            j=j+1;
        }
//fourth part of program
        int k=1;
        while(k<=(n-a)-1-i)
        {
            cout<<" "<<" ";
            k=k+1;
        }
        j=1;
        while(j<=(n-a)-k)
        {
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
