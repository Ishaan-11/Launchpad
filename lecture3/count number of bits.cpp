#include<iostream>
using namespace std;
int main()
{
    int n,a=0;
    cout<<"enter a number: ";
    cin>>n;
    for(int i=0;i<32;i++)
    {
        if(n&1==1)
        {
            a=a+1;
        }
        n=n>>1;
    }
    cout<<"no. of 1 are: "<<a;
    return 0;
}
