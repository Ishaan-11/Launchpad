#include<iostream>
using namespace std;
int main()
{
    char arr1[100];
    char arr2[100];
    cin.getline(arr1,100);
    cin.getline(arr2,100);
    int ascii[256]={0};
    for(int i=0;arr1[i]!='\0';i++)
    {
        ascii[arr1[i]]++;
    }
    for(int i=0;arr2[i]!='\0';i++)
    {
        ascii[arr2[i]]--;
    }
    for(int i=0;i<256;i++)
    {
        if(ascii[i])
        {
            cout<<"not"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
