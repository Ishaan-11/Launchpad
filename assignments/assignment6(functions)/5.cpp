#include<iostream>
using namespace std;
bool AllQueensAreSafe(int a[100][100],int n)
{
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            if(a[x][y]==1)
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
        }
    }
}
//better version
bool AllQueensAreSafe2(int a[100][100],int n)
{
    int check[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            if(a[x][y]==1)
            {
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
        }
    }
}
int main()
{
    int a[100][100];
    cout<<"to place queen insert 1 else 0"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
    if(AllQueensAreSafe2(a,4))
    {
        cout<<"no queens are crossing each other";
    }
    else
    {
        cout<<"false";
    }
    cout<<endl;
    if(AllQueensAreSafe2(a,4))
    {
        cout<<"no queens are crossing each other";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}
