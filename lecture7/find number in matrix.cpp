#include<iostream>
using namespace std;
int main()
{
    int n,m,a[10][10];
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
