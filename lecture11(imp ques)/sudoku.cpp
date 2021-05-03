#include<iostream>
using namespace std;
bool place(int a[100][100],int n,int x,int y,int k)
{
    int move[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int l=0;l<4;l++)
    {
        for(int i=x+move[l][0],j=y+move[l][1];i>=0&&j>=0&&i<n&&j<n;i=i+move[l][0],j=j+move[l][1])
        {
            if(a[i][j]==k)
            {
                return false;
            }
        }
    }
    for(int i=(x/3)*3,p=0;p<3;i++,p++)
    {
        for(int j=(y/3)*3,q=0;q<3;j++,q++)
        {
            if(i==x&&j==y)
            {
                continue;
            }
            if(a[i][j]==k)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku(int a[100][100],int n,int i,int j)
{
    if(j==n)
    {
        return true;
    }
    if(i==n)
    {
        bool done=sudoku(a,n,0,j+1);
        if(done)
        {
            return true;
        }
        return false;
    }
    if(a[i][j]==0)
    {
        for(int k=1;k<10;k++)
        {
            if(place(a,n,i,j,k))
            {
                a[i][j]=k;
                bool done2=sudoku(a,n,i+1,j);
                if(done2)
                {
                return true;
                }
                a[i][j]=0;
            }
        }
        if(a[i][j]==0)
        {
            return false;
        }
    }
    bool done3=sudoku(a,n,i+1,j);
    if(done3)
    {
        return true;
    }
    return false;
}
int main()
{
    int a[100][100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    sudoku(a,n,0,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
