/*
Take sb (source number system base), db (destination number system base) and sn (number in source format).
Write a function that converts sn to its counterpart in destination number system.
Print the value returned.
Constraints:
0 < N <= 1000000000
Sample Input:
8
2
33
Sample Output:
11011
Explanation:
All input output is as integers and in separate lines.

Time Limit: 2 sec
*/
#include <iostream>
using namespace std;
int power(int x,int n)
{
    int pow=1;
    for(int i=1;i<=n;i++)
    {
        pow=pow*x;
    }
    return pow;
}
int main()
{
    int sb,db,n,a,i=0,b=0,c=0,j=1;
    cin>>sb;
    cin>>db;
    cin>>n;
    while(n>0)
    {
        a=n%10;
        b=b+power(sb,i)*a;
        n=n/10;
        i++;
    }
    while(b>0)
    {
        a=b%db;
        c=c+a*j;
        b=b/db;
        j=j*10;
    }
    cout<<c;

}

