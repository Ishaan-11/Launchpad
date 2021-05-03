#include<iostream>
using namespace std;
int main()
{
    int a[10][10],n,m;
    cout<<"enter number of rows: ";
    cin>>n;
    cout<<"enter number of columns: ";
    cin>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"given array: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int j=0;j<m;j++)
    {
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n-1;i++)
            {
                if(a[i][j]>a[i+1][j])
                {
                    int temp=a[i][j];
                    a[i][j]=a[i+1][j];
                    a[i+1][j]=temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(a[i][j]>a[i][j+1])
                {
                    int temp=a[i][j];
                    a[i][j]=a[i][j+1];
                    a[i][j+1]=temp;
                }
            }
        }
    }
    cout<<"array after sorting: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int k;
    cout<<"enter number to be searched: ";
    cin>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==k)
            {
                cout<<"found";
                return 0;
            }
        }
    }
    cout<<"not found";
    return 0;
}
