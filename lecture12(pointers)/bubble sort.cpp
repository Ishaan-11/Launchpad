#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
    return;
}
void bubble(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(*(a+j)>*(a+j+1))
            {
                swap(*(a+j),*(a+j+1));
            }
        }
    }
    return;
}
int main()
{
    int a[5];
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>*(a+i);
    }
    bubble(a,5);
    cout<<"after sorting"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<*(a+i);
    }
    return 0;
}
