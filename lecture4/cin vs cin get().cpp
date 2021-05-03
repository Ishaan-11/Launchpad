#include<iostream>
using namespace std;
int main()
{
    char a;
    a=cin.get();
    while(a!='\n')
    {
        cout<<a;
        a=cin.get();
    }
    return 0;
}
