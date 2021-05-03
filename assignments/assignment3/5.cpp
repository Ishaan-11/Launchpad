#include<iostream>
using namespace std;
int main()
{
    int m1,m2,m3;
    char n1,n2,n3;
    cout<<"enter name of first test: ";
    cin>>n1;
    cout<<"enter marks of first test: ";
    cin>>m1;
    cout<<"enter name of second test: ";
    cin>>n2;
    cout<<"enter marks of second test: ";
    cin>>m2;
    cout<<"enter name of third test: ";
    cin>>n3;
    cout<<"enter marks of third test: ";
    cin>>m3;
    if(m1<=m2&&m1<=m3)
    {
        cout<<"the best two subject are: ";
        cout<<n2<<" and "<<n3<<endl;
        cout<<"average: "<<(m2+m3)/2;
    }
    else if(m2<=m1&&m2<=m3)
    {
        cout<<"the best two subject are: ";
        cout<<n1<<" and "<<n3<<endl;
        cout<<"average: "<<(m1+m3)/2;
    }
    else
    {
        cout<<"the best two subject are: ";
        cout<<n1<<" and "<<n2<<endl;
        cout<<"average: "<<(m1+m2)/2;
    }
    return 0;
}
