#include<iostream>
using namespace std;
int main()
{
    int n,x,a=1;
    cout<<"enter the value of x: ";
    cin>>x;
    cout<<"enter the value of n: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a=a*x;
    }
    cout<<"x^n(x to the power n) is: "<<a;
    return 0;
}
