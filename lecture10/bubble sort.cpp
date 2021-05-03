#include<iostream>
using namespace std;
/*void bubble_sort(int a[10],int n,int index)
{
    if(index==n)
    {
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    bubble_sort(a,n,index+1);
    return;
}*/
int swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void bubble_sort(int a[10],int n,int index)
{
    if(n==0||n==1)
    {
        return;
    }
    if(index==n-1)
    {
        bubble_sort(a,n-1,0);
        return;
    }
    if(a[index]>a[index+1])
    {
        swap(a[index],a[index+1]);
    }
    bubble_sort(a,n,index+1);
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
    bubble_sort(a,5,0);
    cout<<"array after sorting"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
