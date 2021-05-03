#include<iostream>
using namespace std;
int main()
{
    int n,a,b=0,i=1;
    cout<<"enter a number: ";
    cin>>n;
    while(n!=0)
    {
        a=n%2;
        n=n/2;
        b=b+(i*a);
        i=i*10;
    }
    cout<<"binary of given number is: "<<b;
    return 0;
}
