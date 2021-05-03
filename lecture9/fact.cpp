#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    int x=fact(n-1);
    //cout<<x<<endl;
    return n*x;
}
int main()
{
    cout<<fact(5);
}
