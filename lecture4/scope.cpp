#include<iostream>
using namespace std;
int a=10;
int main()
{
    int a=9;
    cout<<"without scope resolution "<<a;
    cout<<"\nwith scope resolution "<<::a;
    return 0;
}
