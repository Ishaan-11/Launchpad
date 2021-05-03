/*
https://hack.codingblocks.com/contests/c/608/1297
Problem Statements :
Consider the shape of pictures given below :
Imgur
All the above given shapes represents the shape of pipelines.
The arrow points represents that you can either enter into that pipelines
or can leave that pipelines from that point.
Pipeline 1 has four entry points and leaving points and
other six pipelines have two entry points and leaving points.
Examples : For pipeline 1st, you can enter or leave that pipelines from all four points.

A robot is moving into a tunnel.
The tunnel is represented in the shape of matrix and each indices of that matrix represents
one of the shape of above given pipelines. See the below figures.
Imgur
Suppose that Robot is initially at pipeline (2,2) .
So it can able to leave that pipelines in four directions (Left, Right, Up , Down)
i.e into the pipeline (2,1), (2,3), (1,2) and (3, 2).
Robot will move in a particular pipeline only when there is a leaving point into
current pipeline and an entry point in the next pipeline where it wants to move.

Examples :
From pipeline (2, 2) , robot can move into pipeline (2,3) and (1,2) only
but can’t move into the pipeline (2,1) and (3,2) although it can able to leave the cell (2,2)
into left and down directions.

Problem :
You are provided a such kind of above tunnel of pipelines in the form of matrix.
Initially Robot has provided a fixed pipeline (x,y) and an integer L.
Integer L represents that robot can move to that pipeline which is at most (L-1) distance away
from the current pipeline. The index of matrix would be an integer p (1<=p<=7) and
the value of p represents the shape pipelines which is given in the 1st picture.
Your work is to find how many of pipelines it can visit starting from the pipelines
with given index (x,y).

Input Format:
First line contains integer t which is number of test case.
For each test case, it contains following lines.
1st line of each test case contains five integers n, m, x, y, L.
n*m is the dimension of the matrix and (x,y) is starting index of the robot and L is the
maximum number of pipelines it can visit.
Next n lines contains m space separated integers which is the value of index of the matrix.

Constraints:
1<=t<=100
1<=n,m,<=50
1<=L<=2500

Output Format:
Print the output as (#TestCaseNumber Maximum number of pipelines that robot can visit.)

Sample Input:
1
3 3 2 2 5
7 4 2
2 1 5
6 3 6
Sample Output:
#1 7
Explanation:
Robot can start from pipelines (2,2) and visit the other pipelines which upto 4 (L-1)
distance away from the pipelines at index (2,2). (2,2) -> (2,3) and (1,2) , (2, 3) ->(1,3),
(1,2) -> (1,1) -> (2,1) -> (3,1)
Total visited pipelines = (2,2), (2,3), (1,2), (1,3), (1,1), (2,1), (3,1)
*/
#include<iostream>
#include<set>
#include<queue>
using namespace std;
set<int> out[4];
set<int> in[4];
int n,m;
int mat[100][100];
bool visited[100][100];
int bfs(int x,int y,int l)
{
    int ans=0;
    queue<pair<int,pair<int,int>>>q;
    q.push(make_pair(x,make_pair(y,1)));
    visited[x][y]=true;
    ans=1;
    while((!q.empty()) && q.front().second.second<l)
    {
        pair<int,pair<int,int>>p=q.front();
        q.pop();
        int i=p.first;
        int j=p.second.first;
        int k=p.second.second;
        if(i-1>=0 && !visited[i-1][j] && out[0].find(mat[i][j])!=out[0].end() && in[0].find(mat[i-1][j])!=in[0].end())
        {
            visited[i-1][j]=true;
            ans++;
            q.push(make_pair(i-1,make_pair(j,k+1)));
        }
        if(j+1<m && !visited[i][j+1] && out[1].find(mat[i][j])!=out[1].end() && in[1].find(mat[i][j+1])!=in[1].end())
        {
            visited[i][j+1]=true;
            ans++;
            q.push(make_pair(i,make_pair(j+1,k+1)));
        }
        if(i+1<n && !visited[i+1][j] && out[2].find(mat[i][j])!=out[2].end() && in[2].find(mat[i+1][j])!=in[2].end())
        {
            visited[i+1][j]=true;
            ans++;
            q.push(make_pair(i+1,make_pair(j,k+1)));
        }
        if(j-1>=0 && !visited[i][j-1] && out[3].find(mat[i][j])!=out[3].end() && in[3].find(mat[i][j-1])!=in[3].end())
        {
            visited[i][j-1]=true;
            ans++;
            q.push(make_pair(i,make_pair(j-1,k+1)));
        }
    }
    return ans;
}
int main()
{
    out[0].insert(1);out[0].insert(2);out[0].insert(5);out[0].insert(6);
    out[1].insert(1);out[1].insert(3);out[1].insert(6);out[1].insert(7);
    out[2].insert(1);out[2].insert(2);out[2].insert(4);out[2].insert(7);
    out[3].insert(1);out[3].insert(3);out[3].insert(4);out[3].insert(5);
    in[0].insert(1);in[0].insert(2);in[0].insert(4);in[0].insert(7);
    in[1].insert(1);in[1].insert(3);in[1].insert(4);in[1].insert(5);
    in[2].insert(1);in[2].insert(2);in[2].insert(5);in[2].insert(6);
    in[3].insert(1);in[3].insert(3);in[3].insert(6);in[3].insert(7);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int x,y,l;
        cin>>n>>m;
        cin>>x>>y>>l;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
                visited[i][j]=false;
            }
        }
        cout<<"#"<<t<<" "<<bfs(x-1,y-1,l)<<endl;
    }
	return 0;
}
