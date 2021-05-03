/*
Take as input N, the size of a chess board.
We are asked to place N number of queens in it, so that no queen can kill other.

a. Write a recursive function which returns the count of different
distinct ways the queens can be placed across the board. Print the value returned.

b. Write a recursive function which prints all valid configurations (void is the return type for function).

Input Format:
Enter the number N(Size of the chessboard)

Constraints:
None
Output Format:
Display the number of possible ways of arranging N queens and print all the possible arrangements
in a space separated manner

Sample Input:
4
Sample Output:
2
{1-2} {2-4} {3-1} {4-3}  {1-3} {2-1} {3-4} {4-2}
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
bool check(int a[100][100],int n,int x,int y)
{
    int move[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    for(int l=0;l<8;l++)
    {
        for(int i=x+move[l][0],j=y+move[l][1];i>=0 && j>=0 && i<n && j<n;i=i+move[l][0],j=j+move[l][1])
        {
            if(a[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
int count(int a[100][100],int n ,int j)
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
void queen(int a[100][100],int n,int j)
{
    if(j==n)
    {
        for(int x=0;x<n;x++)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i][x])
                {
                    cout<<"{"<<x+1<<"-"<<i+1<<"}"<<" ";
                }
            }
            //cout<<endl;
        }
       cout<<" ";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(check(a,n,i,j))
        {
            a[i][j]=1;
            queen(a,n,j+1);
            /*if(done)
            {
                return true;
            }*/
            a[i][j]=0;
        }
    }
    return;
}
int main()
{
    int a[100][100];
    int n;
    cin>>n;
    cout<<count(a,n,0);
    cout<<endl;
    queen(a,n,0);
	return 0;
}
