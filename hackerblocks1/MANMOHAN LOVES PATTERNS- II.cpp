/*

Help Manmohan to print pattern of a given number. See the output pattern for given input n = 5.


Input Format:
Single integer N denoting number of lines of the pattern.

Constraints:
N<=1000
Output Format:
Pattern.

Sample Input:
5
Sample Output:
1
11
202
3003
40004
Explanation:
If row number is n (>1), total character is n. First and last character is n-1 and rest are 0.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,c=3,a=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int j=1,k=3;
        while(j<=i)
        {
            while(c<=i)
            {
                a++;
                c++;
            }
            cout<<a;
            j++;
            while(k<=i)
            {
                cout<<0;
                j++;
                k++;
            }
        }
        cout<<endl;
    }
	return 0;
}
