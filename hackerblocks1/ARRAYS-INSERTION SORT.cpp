/*

Take as input N, the size of array. Take N more inputs and store that in an array.
 Write a function that insertion sorts the array. Print the elements of sorted array.


Constraints:
Length of Array should be between 1 and 1000.
Sample Input:
4
3
4
2
1
Sample Output:
1
2
3
4
Explanation:
For each test case, write insertion sort to sort them as discuss in the class.
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[j]>a[i])
            {
                int temp=a[i];
                for(int k=0;k<i-j;k++)
                {
                    a[i-k]=a[i-k-1];
                }
                a[j]=temp;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
	return 0;
}
