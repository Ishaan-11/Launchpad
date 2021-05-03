#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int ascii[256]={0};
    cout<<"enter a string: "<<endl;
    cin.getline(a,100);
    for(int i=0;a[i]!='\0';i++)
    {
        ascii[a[i]]++;
    }
    cout<<"compressed string: "<<endl;
    for(int i=0;i<256;i++)
    {
        if(ascii[i])
        {
            cout<<char(i)<<ascii[i];
        }
    }
    return 0;
}
