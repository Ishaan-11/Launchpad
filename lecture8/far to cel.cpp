#include<iostream>
using namespace std;
void far_to_cel()
{
    for(int f=0;f<=300;f=f+20)
    {
        int c=(5*(f-32))/9;
        cout<<f<<" "<<c<<endl;
    }
}
int main()
{
    far_to_cel();
    return 0;
}
