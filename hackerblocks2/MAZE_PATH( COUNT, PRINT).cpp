/*
Take as input N1 and N2, both numbers.
N1 and N2 is the number of rows and columns on a rectangular board.
Our player starts in top-left corner of the board and must reach bottom-right corner.
In one move the player can move 1 step horizontally (right) or 1 step vertically (down).

a. Write a recursive function which returns the count of different ways the player can travel
across the board. Print the value returned.

b. Write a recursive function which returns an ArrayList of moves for all valid paths across the board.
Print the value returned.

e.g. for a board of size 3,3; a few valid paths will be “HHVV”, “VVHH”, “VHHV” etc. c.
Write a recursive function which prints moves for all valid paths across the board
(void is the return type for function).

Input Format:
Enter the number of rows N and columns M

Constraints:
None
Output Format:
Display the total number of paths and display all the possible paths in a space separated manner

Sample Input:
3
3
Sample Output:
6
VVHH VHVH VHHV HVVH HVHV HHVV
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
int maze(int a[100][100],int n,int m,int i,int j)
{
    int c=0;
    if(i==n-1 && j==m-1)
    {
        return 1;
    }
    if(j==m-1)
    {
        return maze(a,n,m,i+1,m-1);
    }
    if(i==n-1)
    {
        return maze(a,n,m,n-1,j+1);
    }
    c=c+maze(a,n,m,i+1,j);
    c=c+maze(a,n,m,i,j+1);
    return c;
}
void maze1(int a[100][100],int n,int m,int i,int j,char b[100])
{
    if(i==n-1 && j==m-1)
    {
        b[i+j+1]='\0';
        cout<<b<<" ";
        return;
    }
    if(j==m-1)
    {
        b[i+j]='V';
        maze1(a,n,m,i+1,m-1,b);
        return;
    }
    if(i==n-1)
    {
        b[i+j]='H';
        maze1(a,n,m,n-1,j+1,b);
        return;
    }
    b[i+j]='V';
    //cout<<"V";
    maze1(a,n,m,i+1,j,b);
    b[i+j]='H';
    maze1(a,n,m,i,j+1,b);
    return;
}
int main()
{
    int n,m,a[100][100];
    char b[100];
    cin>>n;
    cin>>m;
    cout<<maze(a,n,m,0,0);
    cout<<endl;
    maze1(a,n,m,0,0,b);

	return 0;
}
/*
bool safe(int n,int m,int i,int j)
{
    if(i==n || j==m)
    {
        return false;
    }
    return true;
}
void maze2(int n,int m,int i,int j,char b[],int k)
{
    if(i==n-1 && j==m-1)
    {
        cout<<b<<" ";
        return;
    }
    for(int p=0;p<2;p++)
    {
        int x[][2]={{1,0},{0,1}};
        if(safe(n,m,i+x[p][0],j+x[p][1]))
        {
            b[k]=(p==0)?'V':'H';
            maze2(n,m,i+x[p][0],j+x[p][1],b,k+1);
        }
    }
    return;
}
*/
