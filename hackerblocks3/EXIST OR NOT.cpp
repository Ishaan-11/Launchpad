/*
Given an array arr of n length.

You will be given Q queries for the array.
Each query contains a number N.
You have to determine whether a number exist in the array or not

Input Format:
First line of input contains number of test cases T.
First line of each case contains an integer L denoting the length of the array.
The next line contains L space separated integers.
The next line contains an integer Q denoting the number of queries.
 The next Q lines contains a number N to be searched in the array.

Constraints:
1<=t<=12
1<=L<=10^5 (n=number of elements in array).
-10^5<=A[i]<=10^5 (A[i]=ith element of array).
 1<=Q<=10^4
-10^5<=x<=10^5
Output Format:
For each Query print “Yes” if the number is present and “No” if it’s not.

Sample Input:
1
6
12 3 -67 67 34 2
4
4
5
67
7
Sample Output:
No
No
Yes
No
*/
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int l;
        cin>>l;
        unordered_set<int> s;
        for(int j=0;j<l;j++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        int q;
        cin>>q;
        for(int j=0;j<q;j++)
        {
            int y;
            cin>>y;
            if(s.find(y)==s.end())
            {
                cout<<"No"<<endl;
            }
            else
            {
                cout<<"Yes"<<endl;
            }
        }
    }
	return 0;
}
