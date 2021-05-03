/*
Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets.
He has to find whether if the sum of any of the non-empty subsets of the set A is zero.

Input Format:
The first line contains an integer T, which is the total number of test cases. T

test cases follow.

Each test case consists of two lines.

The first line consists of a single integer N, which is the number of elements

present in the set A.

The second line contains the integer in the set.

Constraints:
1 ≤ T ≤10
1 ≤ N ≤ 4
-10^5 ≤ A[i] ≤ 10^5
Output Format:
If the sum of any of the subset is zero, then print “Yes” (without

quotes) else print “No”(without quotes).

Sample Input:
1
4
1 2 3 -3
Sample Output:
Yes
Explanation:
The sum of the subset {3,-3} is zero.
*/
#include<iostream>
using namespace std;
bool sub(int i[100000],int i_ind,int o[100000],int o_ind,int n)
{
    if(i_ind>=n)
    {
        int sum=0,z=0;
        for(int x=0;x<o_ind;x++)
        {
            z=1;
            sum+=o[x];
        }
        if(sum==0 && z==1)
        {
            //cout<<"Yes";
            return true;
        }
        else
        {
            return false;
        }
    }
    o[o_ind]=i[i_ind];
    bool check1=sub(i,i_ind+1,o,o_ind+1,n);
    bool check2=sub(i,i_ind+1,o,o_ind,n);
    if(check1||check2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t,n,a[100000],b[100000];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int p=0;p<n;p++)
        {
            cin>>a[p];
        }
        if(sub(a,0,b,0,n))
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        cout<<endl;
    }
	return 0;
}
