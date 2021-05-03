#include<iostream>
using namespace std;
int main()
{
    int a[4];
    cout<<"enter the elements of array: "<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
    }
    cout<<"the pairs of array are: "<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            cout<<a[i]<<" "<<a[j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
