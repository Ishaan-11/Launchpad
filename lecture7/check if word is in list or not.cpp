#include<iostream>
using namespace std;
int main()
{
    char a[10][100];
    int n;
    cout<<"enter the number of strings: "<<endl;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],100);
    }
    char temp[100];
    cout<<"enter the string to find: "<<endl;
    cin.getline(temp,100);
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;a[i][j]!='\0'&&temp[j]!='\0';j++)
        {
            if(a[i][j]!=temp[j])
            {
                break;
            }
        }
        if(a[i][j]=='\0'&&temp[j]=='\0')
        {
            cout<<"found";
            return 0;
        }
    }
    cout<<"not found";
    return 0;
}
