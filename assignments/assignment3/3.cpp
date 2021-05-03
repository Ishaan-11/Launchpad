#include<iostream>
using namespace std;
int main()
{
    int n,p=0,x,a1,a2,y,d;
    cout<<"how many numbers you want to enter: ";
    cin>>n;
    cout<<"enter numbers:\n";
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(i==1)
        {
            a1=x;
        }
        else if(i==2)
        {
            a2=x;
        }
        else
        {
            d=a2-a1;
            y=a1+(i-1)*d;
            if(x!=y)
            {
                p=1;
            }
        }
    }
    if(p==1)
    {
        cout<<"It is not in A.P";
    }
    else
    {
        cout<<"It is in A.P";
    }
    return 0;
}
