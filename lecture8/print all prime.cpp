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
void print_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(isprime(i)==true)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int n;
    cout<<"enter a number: ";
    cin>>n;
    print_prime(n);
    return 0;
}

