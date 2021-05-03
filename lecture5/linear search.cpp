#include<iostream>
using namespace std;
int main()
{
    int a[10]={},x;
    cout<<"enter elements in array: "<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<"enter a number to be searched: "<<endl;
    cin>>x;
    for(int i=0;i<10;i++)
    {
        if(a[i]==x)
        {
            cout<<"found at "<<i;
            return 0;
        }
    }
    cout<<"not found";
    return 0;
}
