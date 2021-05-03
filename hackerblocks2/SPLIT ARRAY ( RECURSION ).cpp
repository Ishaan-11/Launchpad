/*
Take as input N, a number. Take N more inputs and store that in an array.

a. Write a recursive function which counts the number of ways the array could be split in two groups,
so that the sum of items in both groups is equal.
Each number in the array must belong to one of the two groups.
Print the value returned.

b. Write a recursive function which keeps track of ways an array could be split in two groups,
so that the sum of items in both groups is equal.
Each number in the array must belong to one of the two groups.
Return type of function should be void. Print the two groups, each time you find a successful split.


Input Format:
Take as input N, a number. Take N more inputs and store that in an array.

Constraints:
None
Output Format:
Display the number of ways the array can be split and
display all the groups in a comma separated manner

Sample Input:
6
1
2
3
3
4
5
Sample Output:
6
 1 2 3 3 and 4 5
 1 3 5 and 2 3 4
 1 3 5 and 2 3 4
 2 3 4 and 1 3 5
 2 3 4 and 1 3 5
 4 5 and 1 2 3 3
Time Limit: 4 sec
*/
#include<iostream>
using namespace std;
int sum(int x[],int i)
{
    int s=0;
    for(int j=0;j<i;j++)
    {
        s=s+x[j];
    }
    return s;
}
int count(int a[],int ai,int s1[],int s1i,int s2[],int s2i,int n)
{
    int c=0;
    if(ai>=n)
    {
        if(sum(s1,s1i)==sum(s2,s2i))
        {
            return 1;
        }
        return 0;
    }
    s1[s1i]=a[ai];
    c+=count(a,ai+1,s1,s1i+1,s2,s2i,n);
    s2[s2i]=a[ai];
    c+=count(a,ai+1,s1,s1i,s2,s2i+1,n);
    return c;
}
void split(int a[],int ai,int s1[],int s1i,int s2[],int s2i,int n)
{
    if(ai>=n)
    {
        if(sum(s1,s1i)==sum(s2,s2i))
        {
            for(int i=0;i<s1i;i++)
            {
                cout<<s1[i]<<" ";
            }
            cout<<"and ";
            for(int i=0;i<s2i;i++)
            {
                cout<<s2[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    s1[s1i]=a[ai];
    split(a,ai+1,s1,s1i+1,s2,s2i,n);
    s2[s2i]=a[ai];
    split(a,ai+1,s1,s1i,s2,s2i+1,n);
    return;
}
int main()
{
    int n;
    cin>>n;
    int a[100],s1[100],s2[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<count(a,0,s1,0,s2,0,n);
    cout<<endl;
    split(a,0,s1,0,s2,0,n);
	return 0;
}
