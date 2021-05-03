#include<iostream>
using namespace std;
int main()
{
    char a[100],b[100];
    cout<<"enter first string: "<<endl;
    cin.getline(a,100);
    cout<<"enter second string: "<<endl;
    cin.getline(b,100);
    int i=0,j=0;
    while(a[i]!='\0')
    {
        i++;
    }
    while(b[j]!='\0')
    {
        j++;
    }
    if(i!=j)
    {
        cout<<"given strings are not permutation of each other: ";
        return 0;
    }
    int q;
    for(int p=0;p<i;p++)
    {
        for(q=0;q<j;q++)
        {
            if(a[p]==b[q])
            {
                b[q]='\0';
                break;
            }
        }
        if(q==4)
        {
            cout<<"given strings are not permutation of each other: ";
            return 0;
        }
    }
    cout<<"given strings are permutation of each other: ";
    return 0;
}
