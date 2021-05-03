/*

Take as input N, the size of array. Take N more inputs and store that in an array.
 Write a function that selection sorts the array. Print the elements of sorted array.

1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Sort the array using Selection Sort and print that Array.


Constraints:
N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000.
Sample Input:
4
2
-18
45
30
Sample Output:
-18
2
30
45
Explanation:
Write selection sort to sort the given integers in the problem as discuss in the class.
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i];
                for(int k=0;k<i-j;k++)
                {
                    a[i-k]=a[i-1-k];
                }
                a[j]=temp;

            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
	return 0;
}
