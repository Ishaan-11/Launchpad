#include<iostream>
using namespace std;
void merge(int a[10],int start,int mid,int end)
{
    int start1=start,start2=mid+1,end1=mid,end2=end,j=0,temp[10];
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
void merge_sort(int a[10],int start,int end)
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
    int a[10]={4,5,6,1,2,3,4};
    merge_sort(a,0,6);
    for(int i=0;i<7;i++)
    {
        cout<<a[i];
    }
    return 0;
}

