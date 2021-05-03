#include<iostream>
using namespace std;
void assign(char a[100][100],int x,int i,int j)
{
    if(x%2==0)
    {
        a[i][j]='O';
    }
    else
    {
        a[i][j]='X';
    }
    return;
}
void output(char a[100][100],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
void o_x(char a[100][100],int n,int i,int j,int x,int c)
{
    if(i==x&&j==x)
    {
        if(c==n*n)
        {
            output(a,n);
            return;
        }
        assign(a,x,i,j);
        c++;
        o_x(a,n,i,j+1,x,c);
        return;
    }
    else if(i==x&&j<n-x)
    {
        if(c==n*n)
        {
            output(a,n);
            return;
        }
        assign(a,x,i,j);
        c++;
        o_x(a,n,i,j+1,x,c);
        return;
    }
    if(j==n-x)
    {
        o_x(a,n,i+1,n-1-x,x,c);
        return;
    }
    else if(i<n-x&&j==n-1-x)
    {
        if(c==n*n)
        {
            output(a,n);
            return;
        }
        assign(a,x,i,j);
        c++;
        o_x(a,n,i+1,n-1-x,x,c);
        return;
    }
    if(i==n-x)
    {
        o_x(a,n,n-1-x,j-1,x,c);
        return;
    }
    else if(i==n-1-x&&j>=x)
    {
        if(c==n*n)
        {
            output(a,n);
            return;
        }
        assign(a,x,i,j);
        c++;
        o_x(a,n,n-1-x,j-1,x,c);
        return;
    }
    if(j<x)
    {
        o_x(a,n,i-1,x,x,c);
        return;
    }
    else if(j==x&&i>=x+1)
    {
        if(c==n*n)
        {
            output(a,n);
            return;
        }
        assign(a,x,i,j);
        c++;
        if(i==x+1)
        {
            o_x(a,n,x+1,x+1,x+1,c);
            return;
        }
        o_x(a,n,i-1,x,x,c);
        return;
    }
}
int main()
{
    char a[100][100]={};
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    o_x(a,n,0,0,0,0);
    for(int i=0;i<n;i++)
    {
        a[i][n]='\0';
    }
    return 0;
}
