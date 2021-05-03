#include<iostream>
using namespace std;
int main()
{
    int n,count=0;
    cout<<"enter a number: ";
    cin>>n;
    for(int i=5;n/i>0;i=i*5)
    {
        count =count+n/i;
    }
    cout<<"number of trailing zeros are "<<count;
    return 0;
}
