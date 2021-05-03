#include<iostream>
using namespace std;
int main()
{
    int n,i=1,a=1;
    cout<<"enter a number: ";
    cin>>n;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout<<a<<" ";
            a=a+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}
