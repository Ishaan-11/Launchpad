/*
Take as input N, a number. Print the following pattern (for N =4)

*

* *

* * *

* * * *

* * * * *

Input Format:
Enter the value of N

Constraints:
None
Output Format:
Tab separated (*)

Sample Input:
5
Sample Output:
*
*	*
*	*	*
*	*	*	*
*	*	*	*	*
*/
#include<iostream>
using namespace std;
void pattern(int n,int i,int j)
{
    if(i>=n)
    {
        return;
    }
    if(j>i)
    {
        cout<<endl;
        pattern(n,i+1,0);
        return;
    }
    cout<<"*"<<'\t';
    pattern(n,i,j+1);
    return;
}
int main()
{
    int n;
    cin>>n;
    pattern(n,0,0);
	return 0;
}
