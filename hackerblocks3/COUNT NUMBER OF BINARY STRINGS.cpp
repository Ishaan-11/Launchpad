/*
COUNT NUMBER OF BINARY STRINGS
You are provided an integers N.
You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format:
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the the length of Binary String.

Constraints:
1<=t<=100
1<=n<=100

Output Format:
Print the number of all possible binary strings.

Sample Input:
2
2
3
Sample Output:
3
5
Explanation:
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
*/
#include<iostream>
using namespace std;
int bs(int a[],int n,int i)
{
    if(i>=n)
    {
        /*for(int j=0;j<n;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;*/
        return 1;
    }
    int c=0;
    a[i]=0;
    c=c+bs(a,n,i+1);
    a[i]=1;
    if(i>0 && a[i]==1 && a[i-1]==1)
    {
        return c;
    }
    c=c+bs(a,n,i+1);
    return c;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,a[n];
        cin>>n;
        cout<<bs(a,n,0)<<endl;
    }
	return 0;
}
//better method
/*
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        a[0]=1;
        b[0]=1;
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+b[i-1];
            b[i]=a[i-1];
        }
        cout<<a[n-1]+b[n-1]<<endl;
    }
	return 0;
}
*/
