/*
FIND MEDIAN OF BST
Given a binary search tree, Find Its median with O(n) time and O(1) space

Input Format:
The first line contains a number n showing the length of the inorder array of BST
The next n line contains an integer denoting the elements of the array

Constraints:
2 ≤ N ≤ 10^3
Output Format:
Single integer showing the median

Sample Input:
7
20 30 40 50 60 70 80
Sample Output:
50
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
    int fi=0;
    int si=0;
    while(fi+1<n && fi+2<n)
    {
        si++;
        fi=fi+2;
    }
    cout<<a[si];
	return 0;
}
