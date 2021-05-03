#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
    return;
}
int partition(int a[100],int start,int end)
{
    int pivot=a[end];
    int pindex=start;
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[end]);
    return pindex;
}
void quick_sort(int a[100],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int pindex=partition(a,start,end);
    quick_sort(a,start,pindex-1);
    quick_sort(a,pindex+1,end);
    return;
}
int main()
{
    int a[100],n;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    cout<<"after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
