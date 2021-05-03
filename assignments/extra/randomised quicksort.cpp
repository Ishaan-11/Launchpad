/*
Given an array A, of N elements.
Sort the array using quicksort algorithm.(Note : Use randomized quicksort,
otherwise worst case will not pass).

Input Format:
A single integer, N, denoting the number of elements in array.
Next line contains N integers, denoting the elements of array.

Constraints:
1<=N<=2*10^5
|Ai|<=10^9

Output Format:
Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

Sample Input:
5
3 6 4 1 2
Sample Output:
1 2 3 4 6
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void shuffle(int a[],int s,int e)
{
    srand(time(NULL));
    for(int i=e;i>=0;i--)
    {
        int j=rand()%(i+1);
        swap(a[j],a[i]);
    }
}
int partition(int a[],int s,int e)
{
    int pivot=a[e];
    int i=s;
    for(int j=s;j<e;j++)
    {
        if(pivot>a[j])
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[e],a[i]);
    return i;
}
void quicksort(int a[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int i=partition(a,s,e);
    quicksort(a,s,i-1);
    quicksort(a,i+1,e);
    return;
}
int main()
{
    int n;
    cin>>n;
    int a[200000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    shuffle(a,0,n-1);
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
	return 0;
}
