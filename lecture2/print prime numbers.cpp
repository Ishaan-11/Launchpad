#include<iostream>
using namespace std;
int main()
{
    int i=2,n;
    cout<<"enter number till you want to print: ";
    cin>>n;
    while(i<=n)
    {
        int j=2,a=0;
        while(j<i)
        {
            if(i%j==0)
            {
                a=1;
            }
            j=j+1;
        }
        if(a==0)
        {
            cout<<i<<endl;
        }
        i=i+1;
    }
    return 0;
}
