/*
SUPER POWER
Input two numbers a and b . We need to calculate a power b.
*/
#include<iostream>
using namespace std;
int main()
{
    int a,b,c=1;
    cin>>a;
    cin>>b;
    for(int i=1;i<=b;i++)
    {
        c=c*a;
    }
    cout<<c;
	return 0;
}
