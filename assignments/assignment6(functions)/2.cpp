#include<iostream>
using namespace std;
void multiply(int a[][10],int b[][10],int n1,int m1,int n2,int m2)
{
    int c[10][10];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m2;j++)
        {
            int sum=0;
            for(int k=0;k<n2;k++)
            {
                sum=sum+a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    cout<<"matrix after multiplication"<<endl;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m2;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int a[10][10],b[10][10],n1,m1,n2,m2;
    cout<<"enter number of row of first matrix"<<endl;
    cin>>n1;
    cout<<"enter number of column of first matrix"<<endl;
    cin>>m1;
    cout<<"enter number of row of second matrix"<<endl;
    cin>>n2;
    cout<<"enter number of column of second matrix"<<endl;
    cin>>m2;
    if(m1==n2)
    {
        cout<<"enter value of first matrix"<<endl;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<m1;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<"enter value of second matrix"<<endl;
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<m2;j++)
            {
                cin>>b[i][j];
            }
        }
        multiply(a,b,n1,m1,n2,m2);
    }
    else
    {
        cout<<"cannot multiply matrix";
    }
    return 0;
}
