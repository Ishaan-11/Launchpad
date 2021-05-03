#include<iostream>
using namespace std;
int main()
{
    int digit=0,space=0,alpha=0,ch=0;
    char a;
    cout<<"enter characters: ";
    a=cin.get();
    while(a!='$')
    {
        if(a>='0'&&a<='9')
        {
            digit++;
        }
        else if(a==' '||a=='\n'||a=='\t')
        {
            space++;
        }
        else if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
        {
            alpha++;
        }
        ch++;
        a=cin.get();
    }
    cout<<"digits: "<<digit<<endl;
    cout<<"space: "<<space<<endl;
    cout<<"alpha: "<<alpha<<endl;
    cout<<"characters: "<<ch<<endl;
    return 0;
}
