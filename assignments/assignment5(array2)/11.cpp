#include<iostream>
using namespace std;
int main()
{
    int a[10][10],n;
    cout<<"enter value of n for NxN matrix: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int k;
    cout<<"enter number to be searched: ";
    cin>>k;
    int i=0,j=n-1;
    while(i<n&&j>=0)
    {
        if(a[i][j]==k)
        {
            cout<<"found";
            return 0;
        }
        else if(a[i][j]>k)
        {
            j--;
        }
        else if(a[i][j]<k)
        {
            i++;
        }
    }
    cout<<"not found";
    return 0;
}
    /*cout<<"given array: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int j=0;j<n;j++)
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
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n-1;j++)
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
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==k)
            {
                cout<<"found";
                return 0;
            }
        }
    }
    cout<<"not found";
    */

