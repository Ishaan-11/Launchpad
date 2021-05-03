#include<iostream>
using namespace std;
int main()
{
    int n,a,x=0,b=0;
    cout<<"enter a number in binary: ";
    cin>>n;
    while(n!=0)
    {
        int p=1;
        a=n%10;
        n=n/10;
        x=x+1;
        for(int i=1;i<x;i++)
        {
            p=p*2;
        }
        b=b+p*a;
    }
    cout<<"number in decimal is: "<<b;
    return 0;
}
