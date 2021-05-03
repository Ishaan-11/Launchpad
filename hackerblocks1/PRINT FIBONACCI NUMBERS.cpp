/*

Take N as input. Print all fibonnaci numbers less than equal to N.


Constraints:
0 < N <= 1000
Sample Input:
11
Sample Output:
0
1
1
2
3
5
8
Explanation:
Each output should be in separate line.
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=0,b=1;
    cout<<a<<endl;
    cout<<b<<endl;
    int c=a+b;
    while(c<=n)
    {
        cout<<c<<endl;
        a=b;
        b=c;
        c=a+b;
    }
	return 0;
}
