#include<iostream>
using namespace std;
void merge(int a1[],int a2[],int m,int n)
{
    int i=0,j=0,index=0,a3[20];
    while(i<m&&j<n)
    {
        if(a1[i]<a2[j])
        {
            a3[index++]=a1[i++];
            //index++;
            //i++;
        }
        else
        {
            a3[index++]=a2[j++];
        }
    }
    while(i<m)
    {
        a3[index++]=a1[i++];
    }
    while(j<n)
    {
        a3[index++]=a2[j++];
    }
    cout<<"array after merging: "<<endl;
    for(i=0;i<index;i++)
    {
        cout<<a3[i]<<" ";
    }
}
int main()
{
    int a1[5],a2[5];
    cout<<"enter elements of first array (sorted order): "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a1[i];
    }
    cout<<"enter elements of second array (sorted order): "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a2[i];
    }
    merge(a1,a2,5,5);
    return 0;
}
