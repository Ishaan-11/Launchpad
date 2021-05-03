#include<iostream>
using namespace std;
int multiply(int x,int y)
{
    if(y==0)
    {
        return 0;
    }
    return multiply(x,y-1)+x;
}
int main()
{
    cout<<multiply(3,3);
    return 0;
}
