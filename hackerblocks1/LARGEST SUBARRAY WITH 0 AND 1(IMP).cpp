/*
You are given a Given an array containing only 0s and 1s,
find the largest subarray which contain equal no of 0s and 1s.

Input Format:
The first line consists of number of test cases T.
For each test case, consists an integer n as length of the array
and next line contains n space separated integers.

Constraints:
1 <= T <= 10
1 <= n <= 10000000
Output Format:
Print the starting index and final index of the required largest subarray.
If there is no subarray then print None.

Sample Input:
2
7
1 0 0 1 0 1 1
4
1 1 1 1
Sample Output:
0 5
None
Explanation:
For first test case largest subarray lies between index 0 to 5.

Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
int main()
{
    int t,a[10000000],n;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int sum=0,start=0,max=-1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==0)
            {
                sum=-1;
            }
            else
            {
                sum=1;
            }
            for(int j=i+1;j<n;j++)
            {
                if(a[j]==0)
                {
                    sum=sum-1;
                }
                else
                {
                    sum=sum+1;
                }
                if(sum==0 && max<j-i+1)
                {
                    max=j-i+1;
                    start=i;
                }
            }
        }
        if(max==-1)
        {
            cout<<"None";
        }
        else
        {
            cout<<start<<" "<<start+max-1;
        }
        cout<<endl;
    }
}
