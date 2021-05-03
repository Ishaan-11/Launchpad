/*

Take N as input. Print all prime numbers from 2 to N.


Constraints:
1 <= N <= 1000
Sample Input:
2
Sample Output:
2
Explanation:
Each output should be on separate line. A prime number is that number which is divisible by one or itself.
*/
#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=2;
    while(i<=n)
    {
        int a=0,j=2;
        while(j<i)
        {
            if(i%j==0)
            {
                a=1;
            }
            j++;
        }
        if(a==0)
        {
            cout<<i<<endl;
        }
        i++;
    }
	return 0;
}
