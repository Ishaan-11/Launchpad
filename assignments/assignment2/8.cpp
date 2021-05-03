#include<iostream>
using namespace std;
int main()
{
    int n,sum=0,prod=1;
    char a;
    cout<<"enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum=sum+i;
        prod=prod*i;
    }
    cout<<"for sum enter 'A' and for product enter 'B': ";
    cin>>a;
    if(a=='A'||a=='a')
    {
        cout<<"sum from 1...."<<n<<" is: "<<sum;
    }
    else if(a=='B'||a=='b')
    {
        cout<<"product from 1...."<<n<<" is: "<<prod;
    }
    else
    {
        cout<<"wrong input";
        return 0;
    }
    return 0;
}
