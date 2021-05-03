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
    cout<<"the substrings are: "<<endl;
    for(int i=0;i<l;i++)
    {
        for(int j=i;j<l;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<a[k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
