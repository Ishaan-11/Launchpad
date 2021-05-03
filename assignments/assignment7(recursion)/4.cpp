#include<iostream>
#include<cstring>
using namespace std;
void dup(char a[100],int i)
{
    if(a[i]=='\0')
    {
        cout<<a;
        return;
    }
    int l=strlen(a);
    if(a[i]==a[i+1])
    {
        for(int k=0;k<l-i;k++)
        {
            a[i+1+k]=a[i+2+k];
        }
    }
    if(a[i]==a[i+1])
    {
        dup(a,i);
        return;
    }
    dup(a,i+1);
    return;
}
int main()
{
    char a[100];
    cout<<"enter a string"<<endl;
    cin.getline(a,100);
    dup(a,0);
    return 0;
}
