#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
    return;
}
void permutate(char a[100],int i)
{
    if(a[i]=='\0')
    {
        cout<<endl<<a;
    }
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[i],a[j]);
        permutate(a,i+1);
        swap(a[j],a[i]);
    }
    return;
}
int main()
{
    char a[100];
    cout<<"enter a string"<<endl;
    cin.getline(a,100);
    permutate(a,0);
    return 0;
}
