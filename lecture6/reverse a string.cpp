#include<iostream>
using namespace std;
int main()
{
    char a[100];
    cout<<"enter a string:"<<endl;
    cin.getline(a,100);
    int l=0;
    while(a[l]!='\0')
    {
        l++;
    }
    int start=0,end=l-1,temp;
    while(start<end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
/*    int j=0,i=l;
    while(j<l)
    {
        a[j]=a[i-1];
        i--;
        j++;
    }
    a[j]='\0';
    int k=0;
    while(k<=l)
    {
        a[k]=b[k];
*/

    cout<<"the reverse of string is: "<<endl;
    cout<<a;
    return 0;
}
