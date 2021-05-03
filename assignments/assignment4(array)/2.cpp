#include<iostream>
using namespace std;
int main()
{
    int a[5],x;
    cout<<"enter the elements of array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the value of x: ";
    cin>>x;
    cout<<"the pairs of array which sum to "<<x<<" are: "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if((a[i]+a[j])==x)
            {
                cout<<a[i]<<" "<<a[j]<<endl;
            }
        }
    }
    return 0;
}
