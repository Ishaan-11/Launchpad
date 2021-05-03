#include<iostream>
using namespace std;
int main()
{
    int i=1,n;
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
        j=0;
        while(j<i)
        {
            cout<<i+j<<" ";
            j=j+1;
        }
        int k=1;
        while(k<i)
        {
            cout<<i+j-2<<" ";
            j=j-1;
            k=k+1;
        }
        cout<<endl;
        i=i+1;
    }

}
