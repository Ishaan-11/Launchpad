/*
You will be given an array containing only 0s, 1s and 2s.
you have sort the array in linear time that is O(N) where N is the size of the array.

Input Format:
The first line contains N, which is the size of the array.
The following N lines contain either 0, or 1, or 2.

Constraints:
Each input element x, such that x ∈ { 0, 1, 2 }.
Output Format:
Output the sorted array with each element separated by a newline.

Sample Input:
5
0
1
2
1
2
Sample Output:
0
1
1
2
2
Time Limit: 1 sec
*/
#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}
int main()
{
    int n,a[1000000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else if(a[mid]==2)
        {
            swap(a[high],a[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
	return 0;
}
