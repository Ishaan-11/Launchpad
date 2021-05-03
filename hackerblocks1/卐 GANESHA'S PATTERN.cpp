/*

Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

Input Format:
Enter value of N ( >=5 )

Constraints:
N >= 5
Sample Input:
7
Sample Output:
*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
Explanation:
Catch the pattern for the corresponding input and print it accordingly.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    a=n/2;
    for(int i=0;i<a;i++)
    {
        cout<<"*";
        for(int j=1;j<a;j++)
        {
            cout<<" ";
        }
        cout<<"*";
        if(i==0)
        {
            for(int j=0;j<a;j++)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<n-a;i++)
    {
        for(int j=1;j<n-a;j++)
        {
            if(i==0||i==a)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"*";
        for(int j=1;j<a;j++)
        {
            if(i==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"*";
        cout<<endl;
    }
	return 0;
}
