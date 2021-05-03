#include<iostream>
using namespace std;
int main()
{
    int a,x=0;
    for(int i=1;i>0;i++)
    {
        a=3*i+2;
        if(a%4!=0)
        {
            x++;
            cout<<x<<" term = "<<a<<endl;
        }
        if(x==20)
        {
            i=-1;
        }
    }
    return 0;
}
