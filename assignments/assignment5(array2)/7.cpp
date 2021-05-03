#include<iostream>
using namespace std;
int main()
{
    int a[10][10],n,m,c=0;
    cout<<"enter number of row"<<endl;
    cin>>n;
    cout<<"enter number of column"<<endl;
    cin>>m;
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int k,p;
            for(k=0;k<n;k++)
            {
                if(a[i][j]<a[i][k])
                {
                    break;
                }
                //index1=k;
            }
            for(p=0;p<m;p++)
            {
                if(a[i][j]>a[p][j])
                {
                    break;
                }
                //index2=p;
            }
            if(k==n&&p==m)
            {
                c++;
                if(c==1)
                {
                    cout<<"coordinates of saddle points are"<<endl;
                }
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    if(c==0)
    {
        cout<<"no saddle points";
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int max(int a[][10],int n,int i)
{
    int max=-1,M=-1;
    for(int j=0;j<n;j++)
    {
        if(max<a[i][j])
        {
            max=a[i][j];
            M=j;
        }
    }
    return M;
}
int min(int a[][10],int n,int j)
{
    int x=1000,M=-1;
    for(int i=0;i<n;i++)
    {
        if(x>a[i][j])
        {
            x=a[i][j];
            M=i;
        }
    }
    return M;
}
int main() {
    int a[10][10],b[10][10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    } 
    for(int i=0;i<n;i++)
    {
            int Mindex=max(a,n,i);
            int M=a[i][Mindex];
            int mindex=min(a,n,Mindex);
           // cout<<mindex;
            int m=a[mindex][Mindex];
            if(M==m)
            {
                cout<<Mindex<<" "<<mindex<<"|"<<M<<" ";
            }
    }
}

*/