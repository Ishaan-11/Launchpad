#include<iostream>
using namespace std;
int main()
{
    int n,i=2;
    cout<<"enter a number: ";
    cin>>n;
    while(i<n)
    {
        if(n%i==0)
        {
            cout<<n<<" is not a prime number";
            return 0;
        }
        i=i+1;
    }
    cout<<n<<" is a prime number";
    return 0;
}
