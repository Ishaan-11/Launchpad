#include<iostream>
using namespace std;
int main()
{
    int c,f=0;
    while(f<=300)
    {
        c=(5*(f-32)/9);
        cout<<"fahrenheit: "<<f<<" "<<"celsius: "<<c<<endl;
        f=f+20;
    }
    return 0;
}
