#include<iostream>
using namespace std;
void far_to_cel(int start,int end)
{
    for(int f=start;f<=end;f=f+20)
    {
        int c=(5*(f-32))/9;
        cout<<f<<" "<<c<<endl;
    }
}
int main()
{
    int start,end;
    cout<<"enter the starting value: ";
    cin>>start;
    cout<<"enter the ending value: ";
    cin>>end;
    far_to_cel(start,end);
    return 0;
}
