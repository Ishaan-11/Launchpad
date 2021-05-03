/*

Take as input N, a number. Print the pattern according to given input and output section.


Input Format:
Integer

Constraints:
1 <= N <= 100;
Output Format:
Pattern

Sample Input:
3
Sample Output:
*

**

***

*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl<<endl;
    }
	return 0;
}
