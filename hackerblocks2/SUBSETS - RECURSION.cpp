/*
Find all the subsets of a given array that sum to k.

Input Format:
The first line contains an integer N , the size of the array.
The next line conatins N integers. The next line contains an integer K.

Constraints:
0 < N <= 20
Output Format:
Output all the subsets that sum to K. The output should be printed as follows :

Sets with least no of elements should be printed first.
For equal length, elements that appear later in the original set,should be printed first.
Sample Input:
5
1 4 6 5 3
10
Sample Output:
6 4
3 6 1
5 4 1
Explanation:
4 + 6 = 10
1 + 4 + 5 = 10
1 + 3 + 6 = 10
*/
#include<iostream>
using namespace std;
void sub(int i[20],int i_ind,int o[20],int o_ind,int n,int k)
{
    if(i_ind>=n)
    {
        int sum=0;
        for(int x=0;x<o_ind;x++)
        {
            sum+=o[x];
        }
        if(sum==k)
        {
            for(int x=o_ind-1;x>=0;x--)
            {
                cout<<o[x]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    o[o_ind]=i[i_ind];
    sub(i,i_ind+1,o,o_ind,n,k);
    o[o_ind]=i[i_ind];
    sub(i,i_ind+1,o,o_ind+1,n,k);
    o[o_ind]=i[i_ind];
    return;
}
int main()
{
    int i[20],o[20],n,k;
    cin>>n;
    for(int p=0;p<n;p++)
    {
        cin>>i[p];
    }
    cin>>k;
    sub(i,0,o,0,n,k);
    return 0;
}
