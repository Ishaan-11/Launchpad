/*
You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
To learn more about sudoku, go to this link Sudoku-Wikipedia.

Input Format:
First line contains a single integer N.
Next N lines contains N integers each,
where jth integer int ith line denotes the value at ith row and jth column in sudoku grid.
This value is 0, if the cell is empty.

Constraints:
N=6 or N=9,
Solution exists for input matrix.
Output Format:
Print N lines containing N integers each,
where jth integer int ith line denotes the value at ith row and jth column in sudoku grid,
such that all cells are filled.

Sample Input:
9
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
Sample Output:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/
#include <iostream>
using namespace std;
bool isvalid(int a[][100],int n,int x,int y,int k)
{
    int check[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    for(int l=0;l<4;l++)
    {
        for(int i=x+check[l][0],j=y+check[l][1];i>=0 && j>=0 && i<n && j<n;i=i+check[l][0],j=j+check[l][1])
        {
            if(a[i][j]==k)
            {
                return false;
            }
        }
    }
    int A=(x/3)*3;
    int b=(y/3)*3;
    for(int i=A;i<A+3;i++)
    {
        for(int j=b;j<b+3;j++)
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
void print(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sudoku(int a[][100],int n,int i,int j)
{
    if(i==n)
    {
        print(a,n);
        return true;
    }
    if(j==n)
    {
        return sudoku(a,n,i+1,0);
    }
    if(a[i][j]==0)
    {
        for(int k=1;k<=9;k++)
        {
            if(isvalid(a,n,i,j,k))
            {
                a[i][j]=k;
                if(sudoku(a,n,i,j+1))
                {
                    return true;
                }
            }
        }
        a[i][j]=0;
        return false;
    }
    return sudoku(a,n,i,j+1);
}
int main()
{
    int n;
    cin>>n;
    int a[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    sudoku(a,n,0,0);
}

