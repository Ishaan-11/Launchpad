/*
ROBOT MOVEMENT ON A GRID
A robot is moving on a rectangular grid.
For testing the intelligence level of robot,
there are three locations in the grid are specified as “check-in” points and
the robot is supposed to radio a progress report from these points when it is one-fourth,
one-half, and three-fourths of the way through it’s tour of inspection.

The robot must begin its tour of the grid from the lower left corner,
designated in (row,column) coordinates as (0,0),
visiting every other grid location exactly once and ending its tour in row 0, column 1.
The robot is able to move only one square per time step in one of the four compass directions:
Left, right, up , down.

You are to design a program that determines how many different tours are possible
for a given grid size and a sequence of three check-in points.

Example : Suppose the size of the grid is 3*6 and three "check-in" points
are (2,1) , (2,4) and (0,4). So the possible number of tours are 2 which is given below.

Imgur

Input Format:
First line contains integer t which is number of test case.
For each test case, it contains two lines.
First line contains two integers m, n which represents the size of the grid.
Second line contain six integers which is the check in point of the rectangular grid.

Constraints:
1<=t<=10
2<= m,n <=8

Output Format:
Print the number of tours for each given input similar to the sample TestCase output output below.

Sample Input:
1
3 6
2 1 2 4 0 4
Sample Output:
Case 1: 2
*/
#include<iostream>
using namespace std;
int x[3],y[3],n,m;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int robot(int r,int c,int step,bool visited[][10])
{
    if(r<0 || c<0 || r>=m || c>=n)
    {
        return 0;
    }
    if(step==n*m &&(r!=0||c!=1))
    {
        return 0;
    }
    for(int i=1;i<=3;i++)
    {
        if(step==(i*n*m)/4 && (r!=x[i-1]||c!=y[i-1]))
        {
            return 0;
        }
    }
    if(r==0 && c==1 && step==n*m)
    {
        return 1;
    }
    int count=0;
    for(int i=0;i<4;i++)
    {
        int x=r+dir[i][0],y=c+dir[i][1];
        if(!visited[x][y])
        {
            visited[x][y]=true;
            count+=robot(x,y,step+1,visited);
            visited[x][y]=0;
        }
    }
    return count;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>m>>n;
        for(int i=0;i<3;i++)
        {
            cin>>x[i]>>y[i];
        }
        bool visited[10][10]={0};
        cout<<"Case "<<t<<": "<<robot(0,0,1,visited)<<endl;
    }
	return 0;
}
