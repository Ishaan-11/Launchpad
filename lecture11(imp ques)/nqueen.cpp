#include<iostream>
using namespace std;
bool AllQueensAreSafe(int a[100][100],int n,int x,int y)
{
    for(int i=x+1,j=y;i<n;i++)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x-1,j=y;i>=0;i--)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x,j=y+1;j<n;j++)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x,j=y-1;j>=0;j--)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x+1,j=y+1;i<n&&j<n;i++,j++)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x-1,j=y+1;i>=0&&j<n;i--,j++)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    for(int i=x+1,j=y-1;i<n&&j>=0;i++,j--)
    {
        if(a[i][j])
        {
            return false;
        }
    }
    return true;
}
//better version
bool AllQueensAreSafe2(int a[100][100],int n,int x,int y)
{
    int check[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int l=0;l<8;l++)
    {
        for(int i=x+check[l][0],j=y+check[l][1];i>=0&&j>=0&&i<n&&j<n;i=i+check[l][0],j=j+check[l][1])
        {
            if(a[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool nqueens(int a[100][100],int n,int j)
{
    if(j==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(AllQueensAreSafe(a,n,i,j))
        {
            a[i][j]=1;
            bool done=nqueens(a,n,j+1);
            if(done)
            {
                return true;
            }
            a[i][j]=0;
        }
    }
    return false;
}
int main()
{
    int a[100][100];
    nqueens(a,4,0);
    return 0;
}
