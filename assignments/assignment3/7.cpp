#include<iostream>
using namespace std;
int main()
{
    int n,a,even=0,odd=0;
    cout<<"enter a number: ";
    cin>>n;
    while(n>0)
    {
        a=n%10;
        n=n/10;
        if(a%2==0)
        {
            even=even+a;
        }
        else
        {
            odd=odd+a;
        }
    }
    cout<<"sum of even digits is: "<<even<<endl;
    cout<<"sum of odd digits is: "<<odd;
    return 0;
}
