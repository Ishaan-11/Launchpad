#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //peak at even
    for(int i=0;i<n;i=i+2)
    {
        //check left
        if(i>0 && a[i-1]>a[i])
        {
            swap(a[i],a[i-1]);
        }
        //check right
        if(i<n-1 && a[i+1]>a[i])
        {
            swap(a[i],a[i+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}

