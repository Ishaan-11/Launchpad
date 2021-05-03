#include<iostream>
using namespace std;
void f()
{
    //int i=5;
    static int i=5;
    i++;
    cout<<i<<endl;
    return;
}
void f1(int n)
{
    static int i=5;
    if(n<=1)
    {
        return;
    }
    cout<<i<<endl;
    f1(i--);
    return;
}
int main()
{
    /*
    f();
    f();
    f();
    */
    f1(7);
    const int x=5;
    x=6;
    cout<<x<<endl;
    return 0;
}
