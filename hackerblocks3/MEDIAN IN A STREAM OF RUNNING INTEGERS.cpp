/*
MEDIAN IN A STREAM OF RUNNING INTEGERS
You are given a running data stream of n integers.
You read all integers from that running data stream and find effective median of elements
read so far in efficient way. All numbers are distinct in the data stream.

Input Format:
First line contains integer t as number of test cases. Each test case contains following input.
First line contains integer n which represents the length of the data stream and
next line contains n space separated integers.

Constraints:
1 < t < 100
1< n < 1000

Output Format:
Print the effective median of running data stream..

Sample Input:
1
6
5 15 1 3 2 8
Sample Output:
5 10 5 4 3 4
Explanation:
Read print 5 5 5 15 ([5+15]/2)=10 5 15 1 (1 5 15) 5 5 15 1 3 (1 3 5 15) (5+3)/2 = 4 So on….
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int balance(int max,int min)
{
    if(max==min)
    {
        return 0;
    }
    else if(max<min)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int get_meadian(priority_queue<int> &max,priority_queue<int,vector<int>,greater<int>> &min,int &m,int data)
{
    int level=balance(max.size(),min.size());
    switch(level)
    {
        case 0://same size
        if(data<=m)
        {
            max.push(data);
            m=max.top();
        }
        else
        {
            min.push(data);
            m=min.top();
        }
        break;
        case 1://max is greater
        if(data<=m)
        {
            min.push(max.top());
            max.pop();
            max.push(data);
        }
        else
        {
            min.push(data);
        }
        m=(min.top()+max.top())/2;
        break;
        case -1:
        if(data<=m)
        {
            max.push(data);
        }
        else
        {
            max.push(min.top());
            min.pop();
            min.push(data);
        }
        m=(min.top()+max.top())/2;
        break;
    }
    return m;
}
void print_median(int*a,int n)
{
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    int m=0;
    for(int i=0;i<n;i++)
    {
        m=get_meadian(max,min,m,a[i]);
        cout<<m<<" ";
    }
    return;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        int a[1000];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        print_median(a,n);
        cout<<endl;
    }
	return 0;
}
