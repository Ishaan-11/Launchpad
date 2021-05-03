#include<iostream>
using namespace std;
int multiply(int i,int ans[],int size)
{
    int carry=0;
    for(int x=0;x<size;x++)
    {
        int prod=ans[x]*i+carry;
        ans[x]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        ans[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}
void fact(int n)
{
    int ans[500];
    ans[0]=1;
    int size=1;
    for(int i=2;i<=n;i++)
    {
        size=multiply(i,ans,size);
    }
    for(int i=size-1;i>=0;i--)
    {
        cout<<ans[i];
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    fact(n);
	return 0;
}
