#include<iostream>
using namespace std;
void getline(char a[10],int l,char d)
{
    char x;
    int i;
    x=cin.get();
    for(i=0;x!=d&&i<l;i++)
    {
        a[i]=x;
       // i++;
        x=cin.get();
    }
    a[i]='\0';
}
int main()
{
    char a[100];
    getline(a,100,'\n');
    cout<<a;
    return 0;
}
