/*
Take N as input. For a value of N=7, we wish to draw the following pattern :

                            1
                        2 1   1 2
                    3 2 1       1 2 3
                4 3 2 1           1 2 3 4
                    3 2 1       1 2 3
                        2 1   1 2
                            1

Input Format:
Take N as input.

Constraints:
N is odd number.
Output Format:
Pattern should be printed with a space between every two values.

Sample Input:
7
Sample Output:
            1
        2 1   1 2
    3 2 1       1 2 3
4 3 2 1           1 2 3 4
    3 2 1       1 2 3
        2 1   1 2
            1
Explanation:
Catch the pattern and print it accordingly.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a,x=2;
    cin>>n;
    a=n/2;
    for(int i=0;i<a;i++)
    {
        int j;
        for(j=0;j<=n-x;j++)
        {
            cout<<" "<<" ";
        }
        x=x+2;
        for(j=0;j<=i;j++)
        {
            cout<<i+1-j<<" ";
        }
        for(j=1;j<=i;j++)
        {
            cout<<" "<<" ";
        }
        for(j=2;j<=i;j++)
        {
            cout<<" "<<" ";
        }
        for(int k=1;k<x-2*j+i;k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
    int y=0;
    for(int i=0;i<(n-a);i++)
    {
        int j;
        for(j=0;j<y;j++)
        {
            cout<<" "<<" ";
        }
        y=y+2;
        for(j=0;j<(n-a)-i;j++)
        {
            cout<<(n-a)-i-j<<" ";
        }
        for(j=1;j<(n-a)-i;j++)
        {
            cout<<" "<<" ";
        }
        for(j=2;j<(n-a)-i;j++)
        {
            cout<<" "<<" ";
        }
        for(int k=1;k<=(2*(n-a)-j-2*i);k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
	return 0;
}
