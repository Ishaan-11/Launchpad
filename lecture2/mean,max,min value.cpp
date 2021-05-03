#include<iostream>
using namespace std;
int main()
{
    int n,num,i=1,sum=0,l=-10000,s=10000;
    cout<<"how many numbers you want to enter? ";
    cin>>n;
    while(i<=n)
    {
        cout<<"enter "<<i<<" number: ";
        cin>>num;
        sum=sum+num;
        if(num>l)
        {
            l=num;
        }
        if(num<s)
        {
            s=num;
        }
        i=i+1;
    }
    cout<<"mean is: "<<(sum/n);
    cout<<"\nlargest number is: "<<l;
    cout<<"\nsmallest number is: "<<s;
    return 0;
}
