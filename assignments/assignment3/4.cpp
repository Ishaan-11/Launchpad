#include<iostream>
using namespace std;
int main()
{
    int n,c,a,b=0;
    cout<<"enter a number: ";
    cin>>c;
    n=c;
    while(n>0)
    {
        a=n%10;
        n=n/10;
        b=b+(a*a*a);
    }
    if(b==c)
    {
        cout<<c<<" is an armstrong number";
    }
    else
    {
        cout<<c<<" is not an armstrong number";
    }
    return 0;
}
