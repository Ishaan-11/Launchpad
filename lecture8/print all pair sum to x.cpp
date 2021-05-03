#include<iostream>
using namespace std;
void sum(int a[5],int n,int x)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==x)
            {
                cout<<a[i]<<" "<<a[j]<<endl;
                c++;
            }
        }
    }
    if(c==0)
    {
        cout<<"no pair found";
    }
}
int main()
{
    int a[5];
    cout<<"enter 5 elements in array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    int x;
    cout<<"enter value of x: "<<endl;
    cin>>x;
    sum(a,5,x);
    return 0;
}
