#include<iostream>
using namespace std;
int stairs(int n)
{
    int c=0;
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    c+=stairs(n-1);
    c+=stairs(n-2);
    c+=stairs(n-3);
    return c;
}
int main()
{
    int n;
    cout<<"enter number of stairs "<<endl;
    cin>>n;
    cout<<"number of ways are "<<stairs(n);
    return 0;
}
