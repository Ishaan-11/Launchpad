/*

Take N (number of rows), print the following pattern (for N = 4)
0
1 1
2 3 5
8 13 21 34


Constraints:
0 < N < 100
Sample Input:
4
Sample Output:
0
1    1
2    3     5
8   13    21    34
Explanation:
Each number is separated from other by a tab. For given input n,
You need to print n(n+1)/2 fibonacci numbers. Kth row contains , next k fibonacci numbers.
*/
#include<iostream>
using namespace std;
int main() {
    int n,a=0,b=1,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<a<<'\t';
            c=a+b;
            a=b;
            b=c;
        }
        cout<<endl;
    }
	return 0;
}
