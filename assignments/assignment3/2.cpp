#include<iostream>
using namespace std;
int main()
{
    cout<<"leap years b/w 2000 and 3000: "<<endl;
    for(int i=2000;i<=3000;i++)
    {
        if(i%4==0)
        {
            if((i%100==0)&&(i%400==0))
            {
                cout<<i<<endl;
            }
            else if(i%100!=0)
            {
                cout<<i<<endl;
            }
        }
    }
    return 0;
}
