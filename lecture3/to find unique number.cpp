#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"how many numbers you want to enter? ";
    cin>>n;
    int x,i=1,unique=0;
    while(i<=n)
    {
        cout<<"\nenter "<<i<<" number";
        cin>>x;
        unique=unique^x;
        i++;
    }
    cout<<"\nunique number is: "<<unique<<endl;
    return 0;
}
