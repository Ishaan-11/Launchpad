/*
You are given an empty chess board of size N*N.
Find the number of ways to place N queens on the board,
such that no two queens can kill each other in one move.
A queen can move vertically, horizontally and diagonally.

Input Format:
A single integer N, denoting the size of chess board.

Constraints:
1<=N<=11
Output Format:
A single integer denoting the count of solutions.

Sample Input:
4
Sample Output:
2
Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
bool issafe(int a[11][11],int n,int i,int j)
{
    int check[8][2]={{-1,0},{1,0},{0,1},{0,-1},
                     {-1,1},{1,1},{1,-1},{-1,-1}};
    for(int l=0;l<8;l++)
    {
        for(int x=i+check[l][0],y=j+check[l][1];x>=0 && y>=0 && x<n && y<n;x=x+check[l][0],y=y+check[l][1])
        {
            if(a[x][y])
            {
                return false;
            }
        }
    }
    return true;
}
int nqueen(int a[11][11],int n,int j)
{
    if(j==n)
    {
        return 1;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(issafe(a,n,i,j))
        {
            a[i][j]=1;
            c=c+nqueen(a,n,j+1);
            a[i][j]=0;
        }
    }
    return c;
}
int main()
{
    int a[11][11];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    cout<<nqueen(a,n,0);
	return 0;
}
