/*
Aman, Sahil’s friend, recently learnt about Trees and is very excited!

One day, Sahil gives Aman a graph and asks him to determine whether the graph

is tree or not. Help Aman to identify whether the incoming graph is a tree or not.

He is given N, the number of vertices in the graph and the degree of each vertex.

Input Format:
First line contains an integer N,
the number of vertices in the graph Second line contains N space separated integers,
the degrees of N vertices

Constraints:
1<=N<=1000
1<=Degree<=1000

Output Format:
Print “Yes” (without quotes) if the graph is a tree or “No” (without quotes) otherwise

Sample Input:
3
1 2 1
Sample Output:
Yes
Time Limit: 2 sec
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum=sum+x;
    }
    //cout<<sum;
    if(sum==2*(n-1))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
	return 0;
}
