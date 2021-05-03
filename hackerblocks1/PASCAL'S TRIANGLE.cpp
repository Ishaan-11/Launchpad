/*
Take as input N, a number. Print the pascal triangle of given input N.
As an example, pascal's triangle for n=6 is given below.

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1


Input Format:
Enter a number N

Constraints:
None
Output Format:
Display the resulting pascal's triangle

Sample Input:
4
Sample Output:
1
1	1
1	2	1
1	3	3	1
Explanation:
Google about pascal's triangle.
*/
#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    return fact(n-1)*n;
}
int ncr(int n,int r)
{
    return (fact(n)/(fact(n-r)*fact(r)));
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<ncr(i,j)<<'\t';
        }
        cout<<endl;
    }
	return 0;
}
