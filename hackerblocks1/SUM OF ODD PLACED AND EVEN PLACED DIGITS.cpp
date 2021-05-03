/*

Take N as input. Print the sum of its odd placed digits and sum of its even placed digits.


Constraints:
0 < N <= 1000000000
Sample Input:
2635
Sample Output:
11
5
Explanation:
5 is present at 1st position, 3 is present at 2nd position, 6 is present at 3rd position and 2 is present at 4th position.

Sum of odd placed digits on first line. 5 and 6 are placed at odd position. Hence odd place sum is 5+6=11

Sum of even placed digits on second line. 3 and 2 are placed at even position. Hence even place sum is 3+2=5
*/
#include<iostream>
using namespace std;
int main() {
    int n,x=1,odd=0,even=0,a;
    cin>>n;
    while(n>0)
    {
        a=n%10;
        if(x%2==0)
        {
            even=even+a;
        }
        else
        {
            odd=odd+a;
        }
        x++;
        n=n/10;
    }
    cout<<odd<<endl;
    cout<<even;
	    return 0;
}
