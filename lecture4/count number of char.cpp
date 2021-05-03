#include<iostream>
using namespace std;
int main()
{
    int c=0;
    char a;
    cout<<"enter character: ";
    a=cin.get();
    while(a!='$')
    {
        c++;
        a=cin.get();
    }
    cout<<"number of characters are: "<<c;
    return 0;
}
