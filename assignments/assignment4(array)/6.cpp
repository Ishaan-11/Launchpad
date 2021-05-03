#include<iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"enter elements in array(4 duplicate)"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    int start=0,index=1,end=10-1;
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
    return 0;
}

