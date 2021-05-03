#include<iostream>
using namespace std;
int main()
{
    char n;
    cout<<"enter a character: ";
    cin>>n;
    if(n>64 && n<91)
    {
        cout<<n<<" is in upper case";
    }
    else if(n>96 && n<123)
    {
        cout<<n<<" is in lower case";
    }
    else
    {
        cout<<"invalid character";
    }
    return 0;
}
