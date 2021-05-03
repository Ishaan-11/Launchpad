/*

Take N (number of rows), print the following pattern (for N = 5)
1
2 2
3 0 3
4 0 0 4
5 0 0 0 5


Constraints:
0 < N < 100
Sample Input:
5
Sample Output:
1
2	2
3	0	3
4	0	0	4
5	0	0	0	5
Explanation:
Each number is separated from other by a tab.If row number is n (>1), total character is n.
First and last character is n and rest are 0.
*/
#include <iostream>
using namespace std;
int main() {
    int n,a=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int j=1;
        while(j<=i)
        {
            cout<<i<<'\t';
            j++;
            for(int k=1;k<=i-j;j++)
            {
                cout<<a<<'\t';
            }
        }
        cout<<endl;
    }

}
