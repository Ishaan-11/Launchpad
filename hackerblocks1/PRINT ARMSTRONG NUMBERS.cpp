/*

Take the following as input.

A number (N1)
A number (N2)
Write a function which prints all armstrong numbers between N1 and N2 (inclusive).

371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3


Constraints:
0 < N1 < 100
N1 < N2 < 10000
Sample Input:
400
1000
Sample Output:
407
Explanation:
Each number in output is in separate line.
*/
#include<iostream>
using namespace std;
int main() {
    int n1,n2,a;
    cin>>n1;
    cin>>n2;
    for(int i=n1;i<=n2;i++)
    {
        int x=i,b=0;
        while(x>0)
        {
            a=x%10;
            b=b+a*a*a;
            x=x/10;
        }
        if(b==i)
        {
            cout<<i<<endl;
        }
    }
	    return 0;
}
