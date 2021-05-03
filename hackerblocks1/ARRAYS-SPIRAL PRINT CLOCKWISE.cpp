/*

Take as input a 2-d array.Print the 2-D array in sprial form clockwise.


Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.
Output Format:
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input:
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output:
11, 12, 13, 14, 24, 34, 44, 43, 42, 41, 31, 21, 22, 23, 33, 32, END
Explanation:
For spiral level clockwise traversal, Go for first row-> last column ->last row -> first column and
then do the same traversal for the remaining matrix .
*/
#include<iostream>
using namespace std;
int main()
{
    int n,m,a[10][10];
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int x=0,count=0;
    while(true)
    {
        for(int i=x,j=x;j<m-x;j++)
        {
            cout<<a[i][j]<<", ";
            count++;
            if(count==n*m)
            {
                cout<<"END";
                return 0;
            }
        }
        for(int i=x+1,j=m-1-x;i<n-x;i++)
        {
            cout<<a[i][j]<<", ";
            count++;
            if(count==n*m)
            {
                cout<<"END";
                return 0;
            }
        }
        for(int i=n-1-x,j=m-2-x;j>=x;j--)
        {
            cout<<a[i][j]<<", ";
            count++;
            if(count==n*m)
            {
                cout<<"END";
                return 0;
            }
        }
        for(int i=n-2-x,j=x;i>x;i--)
        {
            cout<<a[i][j]<<", ";
            count++;
            if(count==n*m)
            {
                cout<<"END";
                return 0;
            }
        }
        x++;
    }
}
