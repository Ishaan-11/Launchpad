#include<iostream>
using namespace std;
void insertion_sort(int a[5],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i];
                for(int k=0;k<i-j;k++)
                {
                    a[i-k]=a[i-k-1];
                }
                a[j]=temp;
                break;
            }
        }
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
    insertion_sort(a,5);
    cout<<"array after sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i];
    }
    return 0;
}

