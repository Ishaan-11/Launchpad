#include<iostream>
using namespace std;
int main()
{
    char a[100];
    cout<<"enter a string: "<<endl;
    cin.getline(a,100);
    int n;
    cout<<"enter the number of characters to be rotated: "<<endl;
    cin>>n;
    int l=0;
    while(a[l]!='\0')
    {
        l++;
    }
    for(int j=l-1;j>=l-n;j--)
    {
        int temp=a[l-1];
        for(int k=l-1;k>0;k--)
        {
            a[k]=a[k-1];
        }
        a[0]=temp;
    }
    cout<<"string after rotation is: "<<endl;
    cout<<a;
    return 0;
}
