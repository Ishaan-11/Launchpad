/*
Find the largest rectangular area possible in a given histogram where
the largest rectangle can be made of a number of contiguous bars.

Input Format:
First line contains a single integer N, denoting the number of bars in th histogram.
Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

Constraints:
1<=N<=10^6
Height of each bar in histogram <= 10^9

Output Format:
Output a single integer denoting the area of the required rectangle.

Sample Input:
5
1 2 3 4 5
Sample Output:
9
*/
#include<iostream>
#include<stack>
using namespace std;
long long int histogram(int a[],int n)
{
    stack<int> s;
    long long area,ans=-1,i;
    s.push(0);
    for(i=1;i<n;i++)
    {
        while(a[i]<a[s.top()])
        {
            int top=s.top();
            s.pop();
            if(s.empty())
            {
                area=a[top]*i;
                ans=max(area,ans);
                break;
            }
            else
            {
                area=a[top]*(i-s.top()-1);
                ans=max(area,ans);
            }
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(s.empty())
        {
            area=a[top]*i;
            ans=max(area,ans);
        }
        else
        {
            area=a[top]*(i-s.top()-1);
            ans=max(area,ans);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<histogram(a,n);
	return 0;
}
