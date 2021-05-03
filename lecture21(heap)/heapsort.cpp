#include<iostream>
using namespace std;
void heapify(int arr[10],int i,int n)
{
    int minindex=i;
    int left=2*i;
    int right=2*i+1;
    if(left < n && arr[minindex]>arr[left])
    {
        minindex=left;
    }
    if(right < n && arr[minindex]>arr[right])
    {
        minindex=right;
    }
    if(minindex!=i)
    {
        swap(arr[minindex],arr[i]);
        heapify(arr,minindex,n);
    }
    return;
}
void heapsort(int arr[10],int n)
{
    //construct tree
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,i,n);
    }
    //extract min
    //place at last
    //heapify
    for(int i=n-1;i>0;i--)
    {
        swap(arr[i],arr[1]);
        heapify(arr,1,i);
    }
    return;
}
int main()
{
    int arr[10]={-1,7,5,6,2,1};
    heapsort(arr,6);
    for(int i=1;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
