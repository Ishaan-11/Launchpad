#include <iostream>
using namespace std;
int main() {
    char a[10][100];
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],100);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            for(int k=0;a[j][k]!='\0';k++)
            {
                if(a[j][k]<a[j+1][k])
                {
                    break;
                }
                if(a[j][k]>a[j+1][k])
                {
                    char temp[100];
                    int x;
                    for(x=0;a[j][x]!='\0';x++)
                    {
                        temp[x]=a[j][x];
                    }
                    temp[x]='\0';
                    for(x=0;a[j+1][x]!='\0';x++)
                    {
                        a[j][x]=a[j+1][x];
                    }
                    a[j][x]='\0';
                    for(x=0;temp[x]!='\0';x++)
                    {
                        a[j+1][x]=temp[x];
                    }
                    a[j+1][x]='\0';
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
