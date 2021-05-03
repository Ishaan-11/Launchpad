#include<iostream>
using namespace std;
bool binary(int a[10],int k,int start,int end)
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
        return binary(a,k,start,mid-1);
    }
    else
    {
        return binary(a,k,mid+1,end);
    }
}
int main()
{
    int a[10],k;
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"enter element to find"<<endl;
    cin>>k;
    if(binary(a,k,0,5-1))
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
    return 0;
}

