#include<iostream>
using namespace std;
int main()
{
    int N,n,m;
    char a[10][10];
    cout<<"enter number: ";
    cin>>N;
    n=N;
    m=N;
    for(int i=0;i<n;i++)
    {
        a[i][m]='\0';
    }
    int x=0,count=0;
    while(true)
    {
        for(int i=x,j=x;j<m-x;j++)
        {
            if(x%2==0)
            {
                a[i][j]='O';
            }
            else
            {
                a[i][j]='X';
            }
            count++;
            if(count==n*m)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<a[i]<<endl;
                }
                return 0;
            }
        }
        for(int i=x+1,j=m-1-x;i<n-x;i++)
        {
            if(x%2==0)
            {
                a[i][j]='O';
            }
            else
            {
                a[i][j]='X';
            }
            count++;
            if(count==n*m)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<a[i]<<endl;
                }
                return 0;
            }
        }
        for(int i=n-1-x,j=m-2-x;j>=x;j--)
        {
            if(x%2==0)
            {
                a[i][j]='O';
            }
            else
            {
                a[i][j]='X';
            }
            count++;
            if(count==n*m)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<a[i]<<endl;
                }
                return 0;
            }
        }
        for(int i=n-2-x,j=x;i>x;i--)
        {
            if(x%2==0)
            {
                a[i][j]='O';
            }
            else
            {
                a[i][j]='X';
            }
            count++;
            if(count==n*m)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<a[i]<<endl;
                }
                return 0;
            }
        }
        x++;
    }

}
