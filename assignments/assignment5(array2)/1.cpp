#include<iostream>
using namespace std;
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
    int start=0,end=5-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==k)
        {
            cout<<"found";
            return 0;
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
    cout<<"not found";
    return 0;
}
