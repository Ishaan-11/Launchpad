#include<iostream>
using namespace std;
int main()
{
    int n,a[10][10]={},b[10][10]={};
    cout<<"enter number of n for NxN matrix: "<<endl;
    cin>>n;
    cout<<"enter elements in array(0s and 1s only)"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                for(int k=0;k<n;k++)
                {
                    b[i][k]=0;
                }
            }
            if(a[j][i]==0)
            {
                for(int k=0;k<n;k++)
                {
                    b[k][i]=0;
                }
            }
        }
    }
    cout<<"array becomes"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=b[i][j];
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
