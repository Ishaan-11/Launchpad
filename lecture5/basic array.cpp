#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<"size of array: "<<sizeof(arr)<<endl;
    cout<<"enter elements: "<<endl;
    //input
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    //output
    cout<<"elements of array are: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
