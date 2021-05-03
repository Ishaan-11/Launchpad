/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty.
The rat can move from position (i,j), down or right on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M).
Find the rightmost path through which, rat can reach this position.
A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1),
if there exists a path from (i,j+1) to (N,M).

Input Format:
First line contains 2 integers, N and M, denoting the rows and columns in the grid.
Next N line contains. M characters each.
An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints:
1<=N,M<=1000
GRID(i,j)='X' or 'O'
Output Format:
If a solution exists: Print N lines, containing M integers each.
A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path
and a 0 denotes that the cell is not covered in the path.
If solution doesn't exist, just print "-1".

Sample Input:
5 4
OXOO
OOOX
OOXO
XOOO
XXOO
Sample Output:
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
0 0 0 1
*/
#include<iostream>
using namespace std;
int maze(char a[1000][1000],int n,int m,int i,int j,int b[1000][1000])
{   int p=1;
    if(a[i][j]=='X')
    {
        return -1;
    }
    if(i==n-1 && j==m-1)
    {
        b[i][j]=1;
        return 0;
    }
    if(j==m-1)
    {
        b[i][j]=1;
        p=maze(a,n,m,i+1,m-1,b);
        if(p==-1)
        {b[i][j]=0;}
        return p;
    }
    if(i==n-1)
    {
        b[i][j]=1;
       p= maze(a,n,m,n-1,j+1,b);
        if(p==-1)
        {b[i][j]=0;}
        return p;
    }
    b[i][j]=1;
    p=maze(a,n,m,i,j+1,b);
    if(p==0)
    {return p;}
    p=maze(a,n,m,i+1,j,b);
    if(p==-1)
    {b[i][j]=0;}
    return p;
}
int main()
{
    int n,m,b[1000][1000]={0};
    char a[1000][1000];
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    if(maze(a,n,m,0,0,b)==0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"-1";
    }
	return 0;
}
//better
/*
#include<iostream>
using namespace std;
bool safe(char a[][1000],int n,int m,int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || a[i][j]=='X')
    {
        return false;
    }
    return true;
}
void print(int sol[][1000],int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool rat(char a[][1000],int n,int m,int sol[][1000],int i,int j)
{
    if(i==n-1 && j==m-1)
    {
        sol[i][j]=1;
        print(sol,n,m);
        return true;
    }
    for(int p=0;p<2;p++)
    {
        int move[][2]={{0,1},{1,0}};
        if(safe(a,n,m,i+move[p][0],j+move[p][1]))
        {
            sol[i][j]=1;
            bool done=rat(a,n,m,sol,i+move[p][0],j+move[p][1]);
            if(done)
            {
                return true;
            }
            sol[i][j]=0;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    char a[1000][1000];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int sol[1000][1000]={};
    if(!rat(a,n,m,sol,0,0))
    {
        cout<<"-1";
    }
	return 0;
}
*/
