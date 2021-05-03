#include<iostream>
#include<cstring>
using namespace std;
void reverse(int n)
{
    int a,b=0;
    while(n>0)
    {
        a=n%10;
        b=b*10+a;
        n=n/10;
    }
    cout<<"reverse of number "<<b<<endl;
}
void reverse(char a[10])
{
    int l=strlen(a);
    int start=0,end=l-1;
    while(start<end)
    {
        char temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
    cout<<"reverse of string is "<<a<<endl;
}
void reverse(int a[10],int n)
{
    cout<<"reverse of array is"<<endl;
    for(int i=n-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    char a[100];
    int b[10];
    cout<<"enter a number"<<endl;
    cin>>n;
    cin.get();
    cout<<"enter a string"<<endl;
    cin.getline(a,100);
    cout<<"enter elements in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>b[i];
    }
    reverse(n);
    reverse(a);
    reverse(b,5);
    return 0;
}
