/*

Take as input N, the size of array. Take N more inputs and store that in an array.
Take N more inputs and store that in another array.
Write a function which returns true if the second array is inverse of first and false otherwise.
Print the value returned.

1.It reads a number N.
2.Take Another N numbers as input and store them in one array.
3.Take Another N numbers as input and store them in an second array.
4.Print true if second array is inverse of first array else print false .


Constraints:
N cannot be Negative. Range of Numbers can be between 0 to N-1.
Sample Input:
5
4
0
2
1
3
1
3
2
4
0
Sample Output:
true
Explanation:
In the sample case, arr1=[4,0,2,1,3],arr2=[1,3,2,4,0].
Inverse of arr1=[1,3,2,4,0] which is equal to arr2.
Therefore, arr2 is inverse of arr1 .Hence, ans is true.
*/
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,b[100],c[100],j=0,min_index;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int min=0;min<n;min++)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==min)
            {
               min_index=i;
            }
        }
        b[j++]=min_index;
    }
    for(int i=0;i<n;i++)
    {
        if(c[i]!=b[i])
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
	return 0;
}
