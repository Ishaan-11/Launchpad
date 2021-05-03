#include<iostream>
using namespace std;
int main()
{
    int n,a,b=0;
    cout<<"enter a number: ";
    cin>>n;
    while(n!=0)
    {
        a=n%10;
        b=b+a;
        n=n/10;
    }
    cout<<"the sum digits is: "<<b;
    return 0;
}
