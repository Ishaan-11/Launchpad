#include<iostream>
using namespace std;
void merge(int a[100],int start,int mid,int end)
{
    int start1=start;
    int end1=mid;
    int start2=mid+1;
    int end2=end;
    int temp[100],j=0;
    while(start1<=end1&&start2<=end2)
    {
        if(a[start1]<a[start2])
        {
            temp[j++]=a[start1++];
        }
        else
        {
            temp[j++]=a[start2++];
        }
    }
    while(start1<=end1)
    {
        temp[j++]=a[start1++];
    }
    while(start2<=end2)
    {
        temp[j++]=a[start2++];
    }
    for(int i=0;i<j;i++)
    {
        a[start++]=temp[i];
    }
    return;
}
void merge_sort(int a[100],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid=(start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
    return;
}
int main()
{
    int a[100];
    cout<<"enter elements in array "<<endl;
    for(int i=0;i<8;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,7);
    cout<<"array after sorting"<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<a[i];
    }
    return 0;
}

