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
        int k=0;
        while(k<i)
        {
            cout<<i+k<<" ";
            k=k+1;
        }
        j=1;
        while(j<i)
        {
            cout<<i+k-2<<" ";
            k=k-1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}
