/*
UGLY NUMBERS
You are provided a sequence of number.
All numbers of that sequence is in increasing order (including 1) and
whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.


Input Format:
First line contains integer t which is number of test case.
For each test case, it contains an integer n.

Constraints:
1<=t<=100
1<=n<=10000

Output Format:
Print nth number of that sequence.

Sample Input:
2
7
10
Sample Output:
8
12
Explanation:
Sequence : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, …..
*/
#include<iostream>
using namespace std;
unsigned long long int number(int n)
{
    unsigned long long int ugly[n];
    ugly[0]=1;
    unsigned long long int ugly_no=1;
    unsigned long long int i2=0,i3=0,i5=0;
    unsigned long long int nmul_2=2,nmul_3=3,nmul_5=5;
    for(unsigned long long int i=1;i<n;i++)
    {
        ugly_no=min(nmul_2,min(nmul_3,nmul_5));
        ugly[i]=ugly_no;
        if(ugly_no==nmul_2)
        {
            i2++;
            nmul_2=ugly[i2]*2;
        }
        if(ugly_no==nmul_3)
        {
            i3++;
            nmul_3=ugly[i3]*3;
        }
        if(ugly_no==nmul_5)
        {
            i5++;
            nmul_5=ugly[i5]*5;
        }
    }
    return ugly_no;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        cout<<number(n)<<endl;
    }
	return 0;
}
