#include<iostream>
using namespace std;
int main()
{
    int n,m,a[10][10];
    cout<<"enter number of rows: ";
    cin>>n;
    cout<<"enter number of columns: ";
    cin>>m;
    cout<<"enter elemnets in array: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int x=0,count=0;
    while(true)
    {
        for(int i=x,j=x;j<m-x;j++)
        {
            cout<<a[i][j]<<" ";
            count++;
            if(count==n*m)
            {
                return 0;
            }
        }
        for(int i=x+1,j=m-1-x;i<n-x;i++)
        {
            cout<<a[i][j]<<" ";
            count++;
            if(count==n*m)
            {
                return 0;
            }
        }
        for(int i=n-1-x,j=m-2-x;j>=x;j--)
        {
            cout<<a[i][j]<<" ";
            count++;
            if(count==n*m)
            {
                return 0;
            }
        }
        for(int i=n-2-x,j=x;i>x;i--)
        {
            cout<<a[i][j]<<" ";
            count++;
            if(count==n*m)
            {
                return 0;
            }
        }
        x++;
    }
}
