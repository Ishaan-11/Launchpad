#include<iostream>
using namespace std;
bool is_sorted(int a[10],int n,int index)
{
    if(index==n-1)
    {
        return true;
    }
    bool right =is_sorted(a,n,index+1);
    if(right==true&&a[index]<=a[index+1])
    {
        return true;
    }
    return false;
}
int main()
{
    int a[10];
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    if(is_sorted(a,5,0))
    {
        cout<<"sorted";
    }
    else
    {
        cout<<"not sorted";
    }
    return 0;
}
