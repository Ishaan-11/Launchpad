/*
In a mathematics class,
Teacher ask Alice to find the number of all n digit distinct integers
which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

Alice is very weak in maths section. Help her to find the number of such n digit integers.


Input Format:
The first line contains T, the number of test cases.
Further T lines contains the value n which is the number of digit in the integer.

Constraints:
1<=T<=40
1<=n<44
Output Format:
For each test case print the number of such n digit integer.

Sample Input:
3
1
2
3
Sample Output:
#1 : 2
#2 : 3
#3 : 5
Explanation:
For n=1 : integers = a, b . For n=2 : integers = aa, ab, ba For n=3 : integers = aaa, aab, aba, baa, bab


#include<iostream>
using namespace std;
int print(int i,int n,bool x)//1->b,0->a
{
    if(i>=n)
    {
        return 1;
    }
    if(x==false)
    {
        return(print(i+1,n,0)+print(i+1,n,1));
    }
    return print(i+1,n,0);
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout<<"#"<<n<<" : "<<print(0,n,0)<<endl;
    }
	return 0;
}
*/
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[50];
    int b[50];
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        a[0]=1;
        b[0]=1;
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+b[i-1];
            b[i]=a[i-1];
        }
        cout<<"#"<<i<<" : "<<a[n-1]+b[n-1]<<endl;
    }
	return 0;
}
