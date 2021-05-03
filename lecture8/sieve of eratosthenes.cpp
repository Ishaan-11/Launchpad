#include<iostream>
using namespace std;
void prime(int n)
{
    bool a[100]={false};
    for(int i=2;i*i<=n;i++)
    {
        if(a[i]==false)
        {
            for(int j=2;i*j<=n;j++)
            {
                a[i*j]=true;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        if(!a[i])
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
    prime(n);
    return 0;
}
