/*
MINIMUM JUMPS REQUIRED
You are provided an array of integers where each element represents the max number of steps
you can take to move ahead.
You need to check that how many minimum steps required to reach at the end of the array.

Input Format:
First line contains integer t which is number of test case.
For each test case, it contains an integers n which the size of array A[].
Next line contains n space separated integers.

Constraints:
1<=t<=50
1<=n<=1000
1<=A[i]<=100

Output Format:
Print the minimum number of jumps.

Sample Input:
1
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output:
3
Explanation:
1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9

*/
#include<iostream>
#include<climits>
using namespace std;
int count(int a[],int n)
{
    if(n==0 || a[0]==0)
    {
        return -1;
    }
    int jump[n];
    jump[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            jump[i]=INT_MAX;
            if(i<=j+a[j] && jump[j]!=INT_MAX)
            {
                jump[i]=min(jump[i],jump[j]+1);
                break;
            }
        }
    }
    return jump[n-1];
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,a[1000];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<count(a,n)<<endl;
    }
	return 0;
}
