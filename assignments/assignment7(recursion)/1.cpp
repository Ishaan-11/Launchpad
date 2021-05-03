#include<iostream>
using namespace std;
bool binary(int a[100],int start,int end,int k)
{
    if(start>end)
    {
        return false;
    }
    int mid=(start+end)/2;
    if(a[mid]==k)
    {
        return true;
    }
    else if(a[mid]>k)
    {
        return binary(a,start,mid-1,k);
    }
    else
    {
        return binary(a,mid+1,end,k);
    }
}
int main()
{
    int a[10],k;
    cout<<"enter elements in array "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"enter number to find"<<endl;
    cin>>k;
    if(binary(a,0,4,k))
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
    return 0;
}
