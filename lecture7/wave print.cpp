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
    cout<<"the wave print is: "<<endl;
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(j%2==0)
            {
                cout<<a[i][j]<<endl;
            }
            else
            {
                cout<<a[n-1-i][j]<<endl;
            }
        }
    }
    return 0;
}
