#include<iostream>
using namespace std;
bool binary(int a[],int n,int k)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==k)
        {
            return true;
        }
        else if(a[mid]>k)
        {
            end =mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return false;
}
int main()
{
    int a[5];
    cout<<"enter 5 elements in array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    int k;
    cout<<"enter element to be searched: "<<endl;
    cin>>k;
    if(binary(a,5,k)==1)
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
    return 0;
}
