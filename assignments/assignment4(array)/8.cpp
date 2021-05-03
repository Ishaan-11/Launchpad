#include<iostream>
using namespace std;
int main()
{
    int a[3],b[3],c[3];
    cout<<"enter elements in first array"<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    cout<<"enter elements in second array"<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<3;i++)
    {
        c[i]=a[i]+b[i];
        if(c[i]>9)
        {
            c[i]=c[i]%10;
            c[i-1]++;
        }
    }
    cout<<"sum of arrays is"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<c[i];
    }
    return 0;
}
