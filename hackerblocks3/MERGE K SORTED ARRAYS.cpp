/*
Given K sorted arrays each with N elements merge them and output the sorted array

Input Format:
First line contains 2 integers K and N.

K is number of arrays.

N is number of elements in each array.

Constraints:
Elements of array <= |10^15|
N <= 10^5
K <= 10
Output Format:
Single line consisting of space separated numbers

Sample Input:
3 4
1 3 5 7
2 4 6 8
0 9 10 11
Sample Output:
0 1 2 3 4 5 6 7 8 9 10 11
Time Limit: 2 sec
*/
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>>p;
    int k,n;
    cin>>k;
    cin>>n;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            p.push(x);
        }
    }
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
	return 0;
}
//better
/*
#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#define value pair<int,pair<int,int>>
using namespace std;
int main()
{
    int k,n;
    cin>>k>>n;
    int a[10][100000];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    priority_queue<value,vector<value>,greater<value>> p;
    for(int i=0;i<k;i++)
    {
        p.push(make_pair(a[i][0],make_pair(i,0)));
    }
    while(p.top().first!=INT_MAX)
    {
        value top=p.top();
        p.pop();
        cout<<top.first<<" ";
        top.second.second++;
        if(top.second.second>=n)
        {
            p.push(make_pair(INT_MAX,make_pair(top.second.first,n)));
        }
        else
        {
            p.push(make_pair(a[top.second.first][top.second.second],make_pair(top.second.first,top.second.second)));
        }
    }
	return 0;
}
*/
