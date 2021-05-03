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
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"factorial = "<<fact(n);
}

