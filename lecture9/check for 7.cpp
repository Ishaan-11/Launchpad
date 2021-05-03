#include<iostream>
using namespace std;
bool check(int a[10],int n,int index)
{
    if(a[index]==7)
    {
        return true;
    }
    if(index==n-1)
    {
        return false;
    }
    return check(a,n,index+1);
}
int first(int a[10],int n,int index)
{
    if(a[index]==7)
    {
        return index;
    }
    if(index==n-1)
    {
        return -1;
    }
    return first(a,n,index+1);
}
/*int last(int a[10],int n,int index,int x)
{
    if(a[index]==7)
    {
        x=index;
    }
    if(index==n-1)
    {
        return x;
    }
    return last(a,n,index+1,x);
}*/
int last(int a[10],int n,int index)
{
    if(index==n)
    {
        return -1;
    }
    int last_index=last(a,n,index+1);
    if(last_index!=-1)
    {
        return last_index;
    }
    if(a[index]==7)
    {
        return index;
    }
    return -1;
}
void all(int a[10],int n,int index)
{
    if(a[index]==7)
    {
        cout<<index<<" ";
    }
    if(index==n-1)
    {
        return;
    }
    all(a,n,index+1);
    return;
}
void all_rev(int a[10],int n,int index)
{
    if(index==n)
    {
        return;
    }
    all_rev(a,n,index+1);
    if(a[index]==7)
    {
        cout<<index<<" ";
    }
    return;
}
int main()
{
    int a[5]={};
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    if(check(a,5,0)==true)
    {
        cout<<"found"<<endl;
        cout<<"first index "<<first(a,5,0)<<endl;
        //cout<<"last index "<<last(a,5,0,-1)<<endl;
        cout<<"last index "<<last(a,5,0)<<endl;
        cout<<"all indices of 7"<<endl;
        all(a,5,0);
        cout<<endl<<"all indices(reverse) of 7"<<endl;
        all_rev(a,5,0);
    }
    else
    {
        cout<<"not found"<<endl;
    }
}
