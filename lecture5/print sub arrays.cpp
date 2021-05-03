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
    cout<<"the sub arrays are: "<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=i;j<4;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<a[k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
