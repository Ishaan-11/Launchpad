#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a number: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<char(65+j)<<" ";
        }
        for(int j=n-i;j>0;j--)
        {
            cout<<char(65+j-1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
