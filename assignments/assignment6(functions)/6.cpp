#include<iostream>
using namespace std;
void remove(int a[10],int n)
{
    int start=0,index=1,end=n-1;
    while(start<end)
    {
        if(a[index]==a[start])
        {
            for(int k=0;k<end-index;k++)
            {
                a[index+k]=a[index+1+k];
            }
            end--;
        }
        if(index>=end)
        {
            start++;
            index=start+1;
        }
        if(a[index]!=a[start])
        {
            index++;
        }
    }
    cout<<"array without duplicates"<<endl;
    for(int i=0;i<=end;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[10];
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    remove(a,10);
    return 0;
}
