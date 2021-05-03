#include<iostream>
using namespace std;
int path(int a[100][100],int m,int n,int i,int j)
{
    int c=0;
    if(i==m-1&&j==n-1)
    {
        return 1;
    }
    if(j==n-1)
    {
        return path(a,m,n,i+1,j);
    }
    if(i==m-1)
    {
        return path(a,m,n,i,j+1);
    }
    c=c+path(a,m,n,i,j+1);
    c=c+path(a,m,n,i+1,j);
    return c;
}
int main()
{
    int a[100][100]={0};
    cout<<path(a,3,3,0,0);
    return 0;
}
