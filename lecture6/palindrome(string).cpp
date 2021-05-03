#include<iostream>
using namespace std;
int main()
{
    char a[100];
    cout<<"enter a string: "<<endl;
    cin.getline(a,100);
    int l=0;
    while(a[l]!='\0')
    {
        l++;
    }
    int start=0,end=l-1;
    while(start<end)
    {
        if(a[start]!=a[end])
        {
            cout<<"not palindrome";
            return 0;
        }
        start++;
        end--;
    }
    cout<<"palindrome";
    return 0;
}
