#include<iostream>
using namespace std;
int main()
{
    int x=0,y=0;
    char a;
    cout<<"long route given by friend(only N,S,E,W): ";
    a=cin.get();
    if(!(a=='N'||a=='S'||a=='E'||a=='W'))
    {
        cout<<"wrong input";
    }
    else
    {
        while(a!='\n')
        {
            if(a=='N')
            {
                x=x+0;
                y=y+1;
            }
            else if(a=='S')
            {
                x=x+0;
                y=y-1;
            }
            else if(a=='E')
            {
                x=x-1;
                y=y+0;
            }
            else if(a=='W')
            {
                x=x+1;
                y=y+0;
            }
            a=cin.get();
        }
        cout<<"minimum moves are: ";
        int i=0,j=0;
        while(i!=x)
        {
            if(x>0)
            {
                i=i+1;
                cout<<"W";
            }
            else
            {
                i=i-1;
                cout<<"E";
            }
        }
        while(j!=y)
        {
            if(y>0)
            {
                j=j+1;
                cout<<"N";
            }
            else
            {
                j=j-1;
                cout<<"S";
            }
        }
        if(i==0&&j==0)
        {
            cout<<"you are at your location";
        }
    }
    return 0;
}
