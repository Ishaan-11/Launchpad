/*

You will be given a number N. You have to code a hollow diamond looking pattern.
The output for N=5 is given in the following image. Screen Shot 2016-06-09 at 2.47.18 pm.png
 hollow diamond

Input Format:
The input has only one single integer N.

Output Format:
Output the given pattern.

Explanation:
Write a code to print above given pattern. No space between any two characters.
*/
#include <iostream>
using namespace std;
int main()
{
    int n=9,k;
    int a=n/2;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=a+2-i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<i;j++)
        {
            cout<<" ";
        }
        for(k=2;k<i;k++)
        {
            cout<<" ";
        }
        for(int j=1;j<=a+2-k;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n-a;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=(n-a)-i;j++)
        {
            cout<<" ";
        }
        for(k=1;k<=(n-a)-i-1;k++)
        {
            cout<<" ";
        }
        for(int j=1;j<=(n-a)-k;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
