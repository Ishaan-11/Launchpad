#include<iostream>
using namespace std;
int main()
{
    char a[100];
    cout<<"enter a string: "<<endl;
    cin.getline(a,100);
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    cout<<"length of string is: "<<i;
    return 0;
}
