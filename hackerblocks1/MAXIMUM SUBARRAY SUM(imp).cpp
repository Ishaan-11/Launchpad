/*
You are given a one dimensional array that may contain both positive and negative integers,
find the sum of contiguous subarray of numbers which has the largest sum. For example,
if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

Input Format:
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints:
1 <= N <= 100000
1 <= t <= 20
0 <= A[i] <= 100000000
Output Format:
The maximum subarray sum

Sample Input:
2
4
1 2 3 4
3
-10 5 10
Sample Output:
10
15
Time Limit: 2 sec
*/
//method 1
#include<iostream>
using namespace std;
int main()
{
    int t,a[100000],n;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int sum=0,max=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
            if(sum<0)
            {
                sum=0;
            }
            else if(max<sum)
            {
                max=sum;
            }
        }
        cout<<max;
        cout<<endl;
    }
}
//method2
#include<iostream>
using namespace std;
int main()
{
    int t,a[100000],n;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int sum=a[0],maxsum=a[0];
        for(int i=1;i<n;i++)
        {
            //sum=max(a[i],sum+a[i]);
            if(a[i]>sum+a[i])
            {
                sum=a[i];
            }
            else
            {
                sum=sum+a[i];
            }
            //maxsum=max(maxsum,sum);
            if(maxsum<sum)
            {
                maxsum=sum;
            }
        }
        cout<<maxsum;
        cout<<endl;
    }
}
