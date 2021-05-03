#include<iostream>
#include<cstring>
using namespace std;
int stoi(char a[100])
{
    if(a[0]=='\0')
    {
        return 0;
    }
    int l=strlen(a);
    int n=a[l-1]-48;
    a[l-1]='\0';
    int x=stoi(a);
    return x*10+n;
}
int power(int x,int n)
{
    int pow=1;
    for(int i=1;i<=n;i++)
    {
        pow=pow*x;
    }
    return pow;
}
int stoi(char a[100],int index)
{
    if(a[index]=='\0')
    {
        return 0;
    }
    int l=strlen(a);
    int x=stoi(a,index+1);
    int n=a[index]-48;
    return x+n*power(10,(l-1)-index);
}
int main()
{
    char a[100];
    cout<<"enter a string(numbers)"<<endl;
    cin.getline(a,100);
    //cout<<stoi(a);
    cout<<stoi(a,0);
}
