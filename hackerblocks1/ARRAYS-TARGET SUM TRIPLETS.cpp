/*

Take as input N, the size of array. Take N more inputs and store that in an array.
 Take as input “target”, a number.
 Write a function which prints all triplets of numbers which sum to target.


Input Format:
First line contains input N.
Next N lines contains the elements of array and N+1 line contains target number.

Constraints:
Length of Array should be between 1 and 1000.
Output Format:
Print all the triplet present in the array.

Sample Input:
9
5
7
9
1
2
4
6
8
3
10
Sample Output:
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
Explanation:
Array = {5, 7, 9, 1, 2, 4, 6 ,8 ,3}. Target number = 10.
Find any three number in the given array which sum to target number.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a[100],k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int p=j+1;p<n;p++)
            {
                if(a[i]+a[j]+a[p]==k)
                {
                    cout<<a[i]<<", "<<a[j]<<" and "<<a[p]<<endl;
                }
            }
        }
    }
	return 0;
}
