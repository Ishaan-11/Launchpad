/*
Take as input N, the size of array.
Take N more inputs and store that in an array.
Take as input M, a number.
Write a recursive function which returns the last index at which M is found in the array
and -1 if M is not found anywhere. Print the value returned.

Input Format:
Enter a number N and add N more numbers to an array, then enter number M to be searched

Constraints:
None
Output Format:
Display the last index at which the number M is found

Sample Input:
5
3
2
1
2
3
2
Sample Output:
3
*/
#include<iostream>
using namespace std;
int last(int a[100],int m,int i,int n)
{
    if(i>=n)
    {
        return -1;
    }
    int x=last(a,m,i+1,n);
    if(x==-1)
    {
        if(a[i]==m)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return x;
    }
}
int main()
{
    int n,m,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    cout<<last(a,m,0,n);
	return 0;
}
