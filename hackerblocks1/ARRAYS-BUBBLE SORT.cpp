/*

Take as input N, the size of array. Take N more inputs and store that in an array.
Write a function that bubble sorts the array. Print the elements of sorted array.

1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Bubble sort the array and print the Array.


Constraints:
N cannot be Negative. Range of Numbers can be between -1000000000 to 100000000.
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
Foe each test case write bubble sorting program to sort the element as discuss the class.
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
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
	return 0;
}
