/*

Take as input N, a number. Print the pattern as given in output section for corresponding input.


Input Format:
Enter value of N

Output Format:
All numbers and stars are Space separated

Sample Input:
5
Sample Output:
1 2 3 4 5
1 2 3 4 *
1 2 3 * * *
1 2 * * * * *
1 * * * * * * *
Explanation:
Catch the pattern for the corresponding input and print them accordingly.
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1-i;j++)
        {
            cout<<j<<" ";
        }
        for(int j=1;j<=i-1;j++)
        {
            cout<<"*"<<" ";
        }
        for(int j=1;j<=i-2;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
	return 0;
}
