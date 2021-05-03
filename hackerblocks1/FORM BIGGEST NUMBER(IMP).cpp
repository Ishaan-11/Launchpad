/*
You are provided an array of numbers.
You need to arrange them in a way that yields the largest value.

Input Format:
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array A[] and
next line contains n space separated integers A[i] .

Constraints:
1<=t<=100
1<=m<=100
1<=A[i]<=10^5
Output Format:
Print the largest value.

Sample Input:
1
4
54 546 548 60
Sample Output:
6054854654
*/
#include<iostream>
using namespace std;
void swap(int &p,int &q)
{
    int temp=p;
    p=q;
    q=temp;
    return;
}
int add(int x,int y)
{
    int a,b=0,i=1;
    while(y>0)
    {
        a=y%10;
        y=y/10;
        b=b+a*i;
        i=i*10;
    }
    b=b+x*i;
    return b;
}
int main()
{
    int t,n,a[100];
    cin>>t;
    for(int p=0;p<t;p++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(add(a[j+1],a[j])>add(a[j],a[j+1]))
                {
                    swap(a[j],a[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
	return 0;
}
