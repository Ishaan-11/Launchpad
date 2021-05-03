/*
Take N as input. For a value of N=5, we wish to draw the following pattern :

                          5 4 3 2 1 0 1 2 3 4 5
                            4 3 2 1 0 1 2 3 4
                              3 2 1 0 1 2 3
                                2 1 0 1 2
                                  1 0 1
                                    0
                                  1 0 1
                                2 1 0 1 2
                              3 2 1 0 1 2 3
                            4 3 2 1 0 1 2 3 4
                          5 4 3 2 1 0 1 2 3 4 5

Input Format:
Take N as input.

Output Format:
Pattern should be printed with a space between every two values.

Sample Input:
5
Sample Output:
 5 4 3 2 1 0 1 2 3 4 5
   4 3 2 1 0 1 2 3 4
     3 2 1 0 1 2 3
       2 1 0 1 2
         1 0 1
           0
         1 0 1
       2 1 0 1 2
     3 2 1 0 1 2 3
   4 3 2 1 0 1 2 3 4
 5 4 3 2 1 0 1 2 3 4 5
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<" "<<" ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<n-j-i<<" ";
        }
        cout<<0<<" ";
        for(int j=1;j<=n-i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" "<<" ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<i-j<<" ";
        }
        cout<<0<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
	return 0;
}
