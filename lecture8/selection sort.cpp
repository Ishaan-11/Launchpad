#include<iostream>
#include<climits>
using namespace std;
void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=INT_MAX,j,min_index;
        for(j=i;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                min_index=j;
            }
        }
        int temp=a[i];
        a[i]=min;
        a[min_index]=temp;
    }
}
int main()
{
    int a[5]={};
    cout<<"enter elements in array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    selection_sort(a,5);
    cout<<"array after sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i];
    }
    return 0;
}

