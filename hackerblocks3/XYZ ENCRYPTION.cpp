/*
XYZ ENCRYPTION
Mike has a string, s of length n and it consists of only 3 characters 'x', 'y' and 'z'.
Now he wants to encrypt the string in the form of a graph.
To convert the string into a graph, he considers n nodes numbered from 1 to n.
There is an edge between node u and node v, if and only if:

*su* and *sv* are same.
*su* and *sv* are neighboring characters, i.e. "x"-"y" or "y"-"z".
Now he has lost the string, but he has a graph.
He wants to check whether there is a string corresponding to this graph or not.
You can observe that a string will form only one graph, but a graph can represent multiple strings.

Input Format:
First line contains two integers, n and m, denoting the number of nodes and
the number of edges in the graph. Next m lines contains two integers each, u and v,
denoting that there is an edge between them.

Constraints:
1<=n<=500
0<=m<=n(n-1)/2
1<=u,v<=n, u is not equal to v.
All the edges are unique.

Output Format:
Print "Yes" if the given graph can represent a string(or strings). Print "No" otherwise.

Sample Input:
3 1
1 2
Sample Output:
Yes
Explanation:
String "xxz" is one of the strings that will form the given graph.

Time Limit: 1 sec
*/
#include<iostream>
#define x 1
#define y 2
#define z 3
using namespace std;
int a[501][501];
int val[501];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }
    int u=-1,v=-1;
    for(int i=1;i<=n && u==-1 ;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][j]!=1)//not connnected
            {
                u=i;
                v=j;
                val[u]=x;
                val[v]=z;
                break;
            }
        }
    }
    if(u==-1)//all of them are connnected
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)//assigning values
    {
        if(i==u || i==v)
        {
            continue;
        }
        if(a[i][u]==1 && a[i][v]==1)//node is connnected to both u and v
        {
            val[i]=y;
        }
        else if(a[i][u]==1)//connnected to only u
        {
            val[i]=x;
        }
        else if(a[i][v]==1)//connnected to only v
        {
            val[i]=z;
        }
        else
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)//verifying
    {
        for(int j=i+1;j<=n;j++)
        {
            if(abs(val[i]-val[j])<=1 && a[i][j]!=1)// x-x,y-y,x-y,y-z,z-z should be connect
            {
                cout<<"No"<<endl;
                return 0;
            }
            if(abs(val[i]-val[j])>1 && a[i][j]==1)//x-z should not be connected
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
	return 0;
}
