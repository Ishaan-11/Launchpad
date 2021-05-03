#include<iostream>
#include<cstring>
using namespace std;
void squeez(char a[10],int l)
{
    int start=0,end=l;
    while(start<end)
    {
        if(a[start]==' '||a[start]=='\t')
        {
            for(int k=0;k<end-start;k++)
            {
                a[start+k]=a[start+1+k];
            }
            end--;
        }
        else
        {
            start++;
        }
    }
    cout<<a;
}
int main()
{
    char a[100];
    cout<<"enter a string"<<endl;
    cin.getline(a,100);
    int l=strlen(a);
    squeez(a,l);
    return 0;
}
