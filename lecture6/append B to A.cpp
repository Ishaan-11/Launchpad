#include<iostream>
using namespace std;
int main()
{
    char a[100];
    char b[100];
    cout<<"enter first string: "<<endl;
    cin.getline(a,100);
    cout<<"enter second string: "<<endl;
    cin.getline(b,100);
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    int j=0;
    cout<<"string after appending: "<<endl;
    while(b[j]!='\0')
    {
        a[i]=b[j];
        i++;
        j++;
    }
    a[i]='\0';
    cout<<a;
    return 0;
}
