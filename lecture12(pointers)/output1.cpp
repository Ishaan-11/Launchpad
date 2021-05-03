#include<iostream>
using namespace std;
void my(int * p)
{
    int q=10;
    p=&q;
    *p+=20;
    cout<<*p<<endl;
}
int main()
{
    int x=10;
    my(&x);
    cout<<x<<endl;
}
