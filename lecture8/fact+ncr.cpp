#include<iostream>
using namespace std;
int fact(int n)
{
    int a=1;
    for(int i=1;i<=n;i++)
    {
        a=a*i;
    }
    return a;
}
int ncr(int n,int r)
{
    int x=fact(n)/(fact(n-r)*fact(r));
    return x;
}
int main()
{
    int n,r;
    cout<<"enter n: ";
    cin>>n;
    cout<<"enter r: ";
    cin>>r;
    cout<<"ncr = "<<ncr(n,r);
}
