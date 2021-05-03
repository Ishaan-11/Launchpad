/*

Take N (number of rows), print the following pattern (for N = 4)

1
2 3
4 5 6
7 8 9 10


Constraints:
0 < N < 100
Sample Input:
4
Sample Output:
1
2	3
4	5	6
7	8	9	10
Explanation:
Each number is separated from other by a tab.
*/
#include <iostream>
using namespace std;
int main() {
    int n,a=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<a<<"\t";
            a++;
        }
        cout<<endl;
    }

}
