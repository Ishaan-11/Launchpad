#include<iostream>
using namespace std;
bool isprime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout<<"enter a number: ";
    cin>>n;
    if(isprime(n)==false)
    {
        cout<<"not prime";
    }
    else
    {
        cout<<"prime";
    }
    return 0;
}
