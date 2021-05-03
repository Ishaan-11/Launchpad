/*

Take as input N, the size of array. Take N more inputs and store that in an array.
Write a function that reverses the array. Print the values in reversed array.

1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Reverse the elements in the Array.
4.Print the reversed Array.


Constraints:
N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000.
Sample Input:
5
0
4
6
8
9
Sample Output:
9
8
6
4
0
Explanation:
In the sample case , arr=[0,4,6,8,9] is reversed to arr=[9,8,6,4,0].
*/
#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
    return;
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int start=0,end=n-1;
    while(start<end)
    {
        swap(a[start++],a[end--]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
	return 0;
}
