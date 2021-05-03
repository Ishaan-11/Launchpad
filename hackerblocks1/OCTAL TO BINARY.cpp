/*

Take N (number in octal format). Write a function that converts it to binary format.
Print the value returned.


Constraints:
0 < N <= 100000000
Sample Input:
33
Sample Output:
11011
Explanation:
Both input and output are integers
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
    int n,a,i=0,b=0,c=0,j=1;
    cin>>n;
    while(n>0)
    {
        a=n%10;
        b=b+power(8,i)*a;
        n=n/10;
        i++;
    }
    while(b>0)
    {
        a=b%2;
        c=c+a*j;
        b=b/2;
        j=j*10;
    }
    cout<<c;

}
