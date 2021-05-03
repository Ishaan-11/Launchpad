/*
Take as input N, a number.
Print odd numbers in decreasing sequence (up until 0) and even numbers in increasing sequence (up until N)
using Recursion.

Constraints:
1 <= N <=1000
Sample Input:
5
Sample Output:
5
3
1
2
4
*/
#include<iostream>
using namespace std;
void print(int n)
{
    if(n==0)
    {
        return;
    }
    if(n%2!=0)
    {
        cout<<n<<endl;
    }
    print(n-1);
    if(n%2==0)
    {
        cout<<n<<endl;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    print(n);
	return 0;
}
