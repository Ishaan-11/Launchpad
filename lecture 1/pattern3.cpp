#include<iostream>
using namespace std;
int main()
{
    int n,i=1;
    cout<<"enter a number: ";
    cin>>n;
    while(i<=n)
    {
        int j=1;
        while(j<=n-i)
        {
            cout<<" "<<" ";
            j=j+1;
        }
        int a=1;j=1;
        while(j<=(2*i)-1)
        {
            cout<<a<<" ";
            a=a+1;
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }
    return 0;
}
