/*
PAIR SUM IN A BST
Given a binary search tree inorder array and a integer S,
find pair of nodes in the BST which sum to S. You can use extra space only O(log n)

Input Format:
The first line contains a number n showing the length of the inorder array of BST
The next n line contains an integer denoting the elements of the array The next line contains S

Constraints:
2 ≤ N ≤ 10^3
Output Format:
Each pair in different line

Sample Input:
5
0
2
4
6
8
6
Sample Output:
0 6
2 4
Time Limit: 2 sec
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==sum)
            {
                cout<<a[i]<<" "<<a[j]<<endl;
            }
        }
    }
	return 0;
}
