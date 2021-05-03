#include<iostream>
using namespace std;
void sub(int i[10],int n,int i_index,int o[10],int o_index)
{
    if(i_index>=n)
    {
        for(int i=0;i<o_index;i++)
        {
            cout<<o[i];
        }
        cout<<endl;
        return;
    }
    o[o_index]=i[i_index];
    sub(i,n,i_index+1,o,o_index+1);
    sub(i,n,i_index+1,o,o_index);
    return;
}
int main()
{
    int i[10]={1,2,3,3,4,5},o[10];
    sub(i,6,0,o,0);
    return 0;
}
