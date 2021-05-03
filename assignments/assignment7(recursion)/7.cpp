#include<iostream>
using namespace std;
void sub(int i[10],int n,int o[10],int ii,int oi,int k)
{
    if(ii>=n)
    {
        int sum=0;
        for(int x=0;x<oi;x++)
        {
            sum+=o[x];
        }
        if(sum==k)
        {
            for(int x=0;x<oi;x++)
            {
                cout<<o[x]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    o[oi]=i[ii];
    sub(i,n,o,ii+1,oi+1,k);
    sub(i,n,o,ii+1,oi,k);
    return;
}
int main()
{
    int i[10],o[10],k,n;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    cout<<"enter elements in array"<<endl;
    for(int x=0;x<n;x++)
    {
        cin>>i[x];
    }
    cout<<"enter a number "<<endl;
    cin>>k;
    cout<<"subsets are"<<endl;
    sub(i,n,o,0,0,k);
    return 0;
}
