#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a number till you want to print: ";
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int a=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                a=1;
            }
        }
        if(a==0)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
