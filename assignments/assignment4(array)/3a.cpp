#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int arr[5]={};
    cout<<"enter the elements in array:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<5;i++)
    {
        int min=INT_MAX,min_ind;
        for(int j=i;j<5;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                min_ind=j;
            }
        }
        int temp=arr[i];
        arr[i]=min;
        arr[min_ind]=temp;
    }
    cout<<"array after sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
