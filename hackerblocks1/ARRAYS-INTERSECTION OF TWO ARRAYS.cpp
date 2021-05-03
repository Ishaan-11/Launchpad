/*
Take as input N, the size of array.
Take N more inputs and store that in an array.
Take N more inputs and store that in another array.
Write a function which gives the intersection of two arrays in an ArrayList of integers
and Print the ArrayList.

Constraints:
Length of Arrays should be between 1 to 1000.
Sample Input:
7
1 2 3 1 2 4 1
2 1 3 1 5 2 2
Sample Output:
[1, 1, 2, 2, 3]

Explanation:
Check which integer is present in both the arrays and add them in an Arraylist .
Print ArrayList as the ans.
*/
#include<iostream>
#include<climits>
using namespace std;
void sort(int a[1000],int k)
{
    for(int i=0;i<k;i++)
    {
    for(int j=0;j<k-1-i;j++)
        {
        if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return;
}
int main()
{
    int n,a[1000],b[1000],c[1000],k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(b,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                b[j]=INT_MIN;
                c[k]=a[i];
                k++;
                break;
            }
        }
    }
    cout<<"[";
    for(int i=0;i<k;i++)
    {
        if(i==0)
        {
            cout<<c[i];
        }
        else
        {
            cout<<", "<<c[i];
        }
    }
    cout<<"]";
	return 0;
}
