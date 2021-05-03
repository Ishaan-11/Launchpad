#include<iostream>
#include<cstring>
using namespace std;
int power(int x,int n)
{
    int pow=1;
    for(int i=1;i<=n;i++)
    {
        pow=pow*x;
    }
    return pow;
}
void hex(char a[10])
{
    int l=strlen(a),x,sum=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            x=(a[i]-48)*power(16,l-1);
        }
        else if(a[i]>='A'&&a[i]<='F')
        {
            x=(a[i]-55)*power(16,l-1);
        }
        sum+=x;
        l--;
    }
    cout<<"integer value is"<<endl<<sum;
}
int main()
{
    char a[100];
    cout<<"enter a hexadecimal string"<<endl;
    cin.getline(a,100);
    hex(a);
    return 0;
}


