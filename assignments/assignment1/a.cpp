#include<iostream>
using namespace std;
int main()
{
    int i=1,n;
    cout<<"enter a number: ";
    cin>>n;
    while(i<=n)
    {
            int k=1;
            while(k<i)
            {
                cout<<" "<<" ";
                k=k+1;
            }
            int l=1;
            while(l<=(2*n+1)-2*i)
            {
                cout<<"*"<<" ";
                l=l+1;
            }
        cout<<endl;
        i=i+1;
    }
}
