#include<iostream>
using namespace std;
int median(int a[4],int b[4],int m,int n)
{
    int med=(m+n)/2;
    int i=0,j=0,index=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
        {
            if(index==med)
            {
                return a[i];
            }
            index++;
            i++;
        }
        else
        {
            if(index==med)
            {
                return b[j];
            }
            index++;
            j++;
        }
    }
    while(i<m)
    {
        if(index==med)
            {
                return a[i];
            }
        index++;
        i++;
    }
    while(j<n)
    {
        if(index==med)
            {
                return b[j];
            }
        index++;
        j++;
    }
}
int main()
{
    int a[4],b[4];
    cout<<"enter elements of first array(sorted order): "<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
    }
    cout<<"enter elements of second array(sorted order): "<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>b[i];
    }
    cout<<"combined median is: "<<endl;
    cout<<median(a,b,4,4)<<" "<<median(a,b,4,4)-1;
    return 0;
}

