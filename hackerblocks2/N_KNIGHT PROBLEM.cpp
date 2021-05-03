/*
N_KNIGHT PROBLEM
Take as input N, the size of a chess board.
We are asked to place N number of Knights in it, so that no knight can kill other.

a. Write a recursive function which returns the count of different distinct ways
the knights can be placed across the board. Print the value returned.

b.Write a recursive function which prints all valid configurations
(void is the return type for function).

Input Format:
Enter the size of the chessboard N

Constraints:
None

Output Format:
Display the number of ways a knight can be placed and print all the possible
arrangements in a space separated manner

Sample Input:
2
Sample Output:
{0-0} {0-1}  {0-0} {1-0}  {0-0} {1-1}  {0-1} {1-0}  {0-1} {1-1}  {1-0} {1-1}
6
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
bool safe(int a[][100],int n,int x,int y)
{
    int check[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},
                     {-2,1},{-1,2},{1,2},{2,1}};
    for(int l=0;l<8;l++)
    {
        int i=x+check[l][0],j=y+check[l][1];
        if(i>=0 && j>=0 && i<n && j<n)
        {
            if(a[i][j])
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
            if(a[i][j])
            {
                cout<<"{"<<i<<"-"<<j<<"} ";
            }
        }
    }
}
int knight(int a[][100],int n,int k,int i,int j)
{
    if(k==n)
    {
        return 1;
    }
    if(i==n)
    {
        return 0;
    }
    int c=0;
    for(;j<n;j++)
    {
        if(safe(a,n,i,j))
        {
            a[i][j]=1;
            c+=knight(a,n,k+1,i,j+1);
            //cout<<"a";
            a[i][j]=0;
        }
    }
    c+=knight(a,n,k,i+1,0);
    return c;
}
void nknight(int a[][100],int n,int k,int i,int j)
{
    if(k==n)
    {
        print(a,n);
        cout<<" ";
        return;
    }
    if(i==n)
    {
        return;
    }
    for(;j<n;j++)
    {
        if(safe(a,n,i,j))
        {
            a[i][j]=1;
            nknight(a,n,k+1,i,j+1);
            a[i][j]=0;
        }
    }
    nknight(a,n,k,i+1,0);
    return;
}
int main()
{
    int n;
    cin>>n;
    int a[100][100]={};
    nknight(a,n,0,0,0);
    cout<<endl<<knight(a,n,0,0,0);
	return 0;
}
