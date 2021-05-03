//(not sure)
#include<iostream>
using namespace std;
void p(int a[10],int n,int i)
{
    if(i>=n)
    {
        cout<<endl;
        return;
    }
    cout<<char(a[i]+64);
    p(a,n,i+1);
    int b=0;
    for(int x=0;x<i;x++)
    {
        b=b*10+a[x];
    }
    if(b>0&&b<27)
    {
        cout<<char(b+64);
    }
    b=0;
    for(int x=i;x<n;x++)
    {
        b=b*10+a[x];
    }
    if(b>0&&b<27)
    {
        cout<<char(b+64);
    }
    cout<<endl;
    return;
}
int main()
{
    int a[10],n;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    p(a,n,0);
    return 0;
}
