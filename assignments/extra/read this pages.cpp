/*
Read the Pages
You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j).
You have to assign these N books to M students,
such that each student has subsegment of books and
the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.


Input Format:
First line contains integers, N and M, denoting the number of books and number of students respectively.
Next line contains N integers, denoting the number of pages in N books.

Constraints:
1<=N<=10^5
1<=M<=N
1<=Pi<=10^9
Output Format:
Print a single integer, denoting the answer.

Sample Input:
4 2
10 20 30 40
Sample Output:
60
Time Limit: 10 sec

*/
#include<iostream>
using namespace std;
bool check(long long a[],long long k,long long n,long long mid)
{
    int cur_pg=0;
    int s=1;
    for(int i=0;i<n;i++)
    {
        if(cur_pg+a[i]>mid)
        {
            s++;
            cur_pg=a[i];
            if(s>k)
            {
                return false;
            }
        }
        else
        {
            cur_pg=cur_pg+a[i];
        }
    }
    return true;
}
int main()
{
    long long int n,k;
    cin>>n>>k;
    long long a[n],sum=0,s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
        s=max(s,a[i]);
    }
    long long e=sum,ans=0;
    while(s<=e)
    {
        long long mid=(s+e)/2;
        if(check(a,k,n,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<ans;
}
