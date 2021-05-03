/*
Take as input N, the size of array.
Take N more inputs and store that in an array.
Take as input M, the size of second array and take M more inputs and store that in second array.
Write a function that returns the sum of two arrays. Print the value returned.

Constraints:
Length of Array should be between 1 and 1000.
Sample Input:
4
1 0 2 9
5
3 4 5 6 7
Sample Output:
3, 5, 5, 9, 6, END
Explanation:
Sum of [1, 0, 2, 9] and [3, 4, 5, 6, 7] is [3, 5, 5, 9, 6] and the first digit represents carry over ,
if any (0 here ) .
*/
#include<iostream>
using namespace std;
int sum(int a,int b)
{
    int s=a+b;
    return s;
}
int main()
{
    int m,n,c[1000]={},x,i,j;
    cin>>m;
    int a[m];
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    cin>>n;
    int b[n];
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    if(n>=m)
    {
        x=n;
        i=m-1;
        j=n-1;
    }
    else
    {
        x=m;
        j=m-1;
        i=n-1;
    }
    while(i>=0&&j>=0)
    {
        if(n>=m)
        {
            c[j]+=sum(a[i],b[j]);
        }
        else
        {
            c[j]+=sum(a[j],b[i]);
        }
        if(c[j]>9&&j==0)
        {
         c[j]=c[j];
        }
        else if(c[j]>9)
        {
            c[j-1]=c[j]/10;
            c[j]=c[j]%10;
        }
        i--;
        j--;
    }
    while(j>=0)
    {
        if(n>=m)
        {
            c[j]+=b[j];
        }
        else
        {
            c[j]+=a[j];
        }
        j--;
    }
    for(i=0;i<x;i++)
    {
        if(i==0 && c[i]>9)
        {
            cout<<(c[i]/10)<<", ";
            c[i]=c[i]%10;
        }
        cout<<c[i]<<", ";
    }
    cout<<"END";
	return 0;
}
