#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int b=0;
    cout<<"enter number in string: "<<endl;
    cin.getline(a,100);
    for(int i=0;a[i]!='\0';i++)
    {
        int n=a[i]-48;
        b=b*10+n;
    }
    cout<<"integer value is "<<b;
    return 0;
}

