/*

Take the following as input.

A number (N1)
A number (N2)
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.


Constraints:
0 < N1 < 100
0 < N2 < 100
Sample Input:
10
4
Sample Output:
5
11
14
17
23
26
29
35
38
41
Explanation:
The output will've N1 terms which are not divisible by N2.
*/
#include <iostream>
using namespace std;
int main()
{
    int n1,n2,j=1,a;
    cin>>n1;
    cin>>n2;
    for(int i=1;j<=n1;i++)
    {
        a=3*i+2;
        if(a%n2!=0)
        {
            cout<<a<<endl;
            j++;
        }
    }
    return 0;
}
