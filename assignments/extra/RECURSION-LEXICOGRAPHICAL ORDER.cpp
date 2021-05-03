/*
RECURSION-LEXICOGRAPHICAL ORDER
Take as input N, a number.
Write a recursive function which prints counting from 1 to N in lexicographical order.
In lexicographical (dictionary) order 10, 100 and 109 will be printed before 11.

Input Format:
Enter a number N.

Constraints:
None

Output Format:
Display all the numbers upto N in a lexicographical order

Sample Input:
10
Sample Output:
0 1 10 2 3 4 5 6 7 8 9
*/
#include<iostream>
using namespace std;
void setarray(int a[],int n)
{
    if(n==1)
    {
        a[0]=0;
        return;
    }
    setarray(a,n-1);
    a[n-1]=n-1;
    return;
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return;
}
int count(int n)
{
    if(n<10)
    {
        return 1;
    }
    return count(n/10)+1;
}
bool small(char ax[],char ay[])
{
    int i=0;
    while(ax[i]!='\0' && ay[i]!='\0')
    {
        if(ax[i]==ay[i])
        {
            i++;
            continue;
        }
        else if(ax[i]<ay[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(ax[i]=='\0')
    {
        return true;
    }
    return false;
}
bool comp(int x,int y)
{
    char ax[10],ay[10];
    int cx=count(x);
    int cy=count(y);
    for(int i=0;i<cx;++i)
    {
        ax[cx-1-i]=(char)(x%10+48);
        x=x/10;
    }
    ax[cx]='\0';
    for(int i=0;i<cy;++i)
    {
        ay[cy-1-i]=(char)(y%10+48);
        y=y/10;
    }
    ay[cy]='\0';
    return small(ax,ay);
}
void sortarray(int a[],int n)
{
    if(n<=1)
    {
        return;
    }
    sortarray(a,n-1);
    if(comp(a[n-1],a[n-2]))
    {
        swap(a[n-1],a[n-2]);
        sortarray(a,n-1);
    }
    return;
}
int main()
{
    int x;
    cin>>x;
    int n=x+1;
    int a[100];
    setarray(a,n);
    sortarray(a,n);
    print(a,n);
}
