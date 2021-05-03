/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty.
The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1).
It wants to reach position (N,M) where it's cheese is waiting for.
There exits a unique path in the grid . Find that path and help the rat reach its cheese.


Input Format:
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each.
An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints:
1 <= N , M <= 10
Output Format:
Print N lines, containing M integers each.
 A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and
a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"

Sample Input:
5 4
OXOO
OOOX
XOXO
XOOX
XXOO
Sample Output:
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 0
0 0 1 1
Time Limit: 2 sec
*/
#include<iostream>
using namespace std;
bool issafe(char a[10][10],int n,int m,int i,int j,bool visited[10][10])
{
    if(a[i][j]=='X' || visited[i][j]==true || i<0 || j<0 || i==n || j==m)
    {
        return false;
    }
    return true;
}
bool rat(char a[10][10],int n,int m,int i,int j,int sol[10][10],bool visited[10][10])
{
    if(i==n-1 && j==m-1)
    {
        sol[i][j]=1;
        for(int p=0;p<n;p++)
        {
            for(int q=0;q<m;q++)
            {
                cout<<sol[p][q]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    visited[i][j]=true;
    for(int x=0;x<4;x++)
    {
        int r[4]={0,0,1,-1};
        int c[4]={1,-1,0,0};
        if(issafe(a,n,m,i+r[x],j+c[x],visited))
        {
            sol[i][j]=1;
            bool z=rat(a,n,m,i+r[x],j+c[x],sol,visited);
            if(z)
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
    cin>>n;
    cin>>m;
    char a[10][10];
    int sol[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sol[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    bool visited[10][10]={0};
    if(!rat(a,n,m,0,0,sol,visited))
    {
        cout<<"NO PATH FOUND";
    }
	return 0;
}
/*
#include<iostream>
using namespace std;
bool safe(char a[][100],int n,int m,int i,int j,bool visited[][100])
{
    if(i<0 || j<0 || i>=n || j>=m || a[i][j]=='X' || visited[i][j]==true)
    {
        return false;
    }
    return true;
}
void print(int sol[][100],int n,int m)
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
bool rat(char a[][100],int n,int m,int i,int j,int sol[][100],bool visited[][100])
{
    if(i==n-1 && j==m-1)
    {
        sol[i][j]=1;
        print(sol,n,m);
        return true;
    }
    visited[i][j]=true;
    for(int p=0;p<4;p++)
    {
        int move[][2]={{0,1},{1,0},{-1,0},{0,-1}};
        if(safe(a,n,m,i+move[p][0],j+move[p][1],visited))
        {
            sol[i][j]=1;
            bool done=rat(a,n,m,i+move[p][0],j+move[p][1],sol,visited);
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
    char a[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int sol[100][100]={};
    bool visited[100][100]={0};
    if(!rat(a,n,m,0,0,sol,visited))
    {
        cout<<"NO PATH FOUND";
    }
	return 0;
}
*/
