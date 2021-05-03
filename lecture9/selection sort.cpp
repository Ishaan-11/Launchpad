#include<iostream>
using namespace std;
void selection_sort(int a[10],int n,int index)
{
    if(index==n)
    {
        return;
    }
    int min=a[index];
    int min_index=index;
    for(int i=index;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            min_index=i;
        }
    }
    a[min_index]=a[index];
    a[index]=min;
    selection_sort(a,n,index+1);
    return;
}
int main()
{
    int a[10];
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    selection_sort(a,5,0);
    cout<<"array after sorting "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
