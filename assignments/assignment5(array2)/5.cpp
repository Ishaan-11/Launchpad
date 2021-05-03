#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char t[100],s[100];
    cout<<"enter string t"<<endl;
    cin.getline(t,100);
    int l=strlen(t);
    cout<<"enter string s"<<endl;
    cin.getline(s,100);
    int index=-1;
    for(int j=0;s[j]!='\0';j++)
    {
        int c=0;
        for(int i=0;s[i+j]!='\0'&&t[i]!='\0';i++)
        {
            if(s[j+i]==t[i])
            {
                c++;
                if(c==l)
                {
                    index=j+i-(l-1);
                    c=0;
                }
            }
        }
    }
    if(index==-1)
    {
        cout<<"t is not in s"<<endl;
    }
    else
    {
        cout<<"the right most position of t in s is: "<<index;
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int main() {
    char a[100],b[100];
    cin.getline(a,100);
    cin.getline(b,100);
    int x=-1;
    for(int i=0;a[i]!='\0';i++)
    {
        int c=i,j;
        for(j=0;b[j]!='\0';j++)
        {
            if(a[c]!=b[j])
            {
                break;
            }
            else if(a[c]==b[j])
            {
                c++;
            }
        }
        if(b[j]=='\0')
        {
            x=i;
        }
    }
    cout<<x;
}
*/
