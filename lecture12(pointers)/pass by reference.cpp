#include<iostream>
using namespace std;
void f(int &x)
{
    x++;
    cout<<x<<endl;
}
int main()
{
    int x=10;
    cout<<x<<endl;
    f(x);
    int &y=x;
    y++;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<&x<<endl;
    cout<<&y<<endl;
    return 0;
}
