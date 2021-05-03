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
bool check(int a[100][100],int n,int x,int y)
{
    int move[8][2]={{1,0},{-1,0},{0,1},{0,-1},
                     {1,1},{-1,-1},{-1,1},{1,-1}};
    for(int l=0;l<8;l++)
    {
        for(int i=x+move[l][0],j=y+move[l][1];i>=0&&j>=0&&i<n&&j<n;i=i+move[l][0],j=j+move[l][1])
        {
            if(a[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
int count(int a[100][100],int n,int j)
{
    int c=0;
    if(j==n)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(check(a,n,i,j))
        {
            a[i][j]=1;
            c+=count(a,n,j+1);
            a[i][j]=0;
        }
    }
    return c;
}
int main()
{
    int a[100][100],n;
    cin>>n;
    cout<<count(a,n,0);
	return 0;
}
