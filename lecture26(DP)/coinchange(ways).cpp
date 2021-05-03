#include<iostream>
using namespace std;
//normal
int coin(int n,int arr[],int size)
{
    if(n<0 || size<=0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    return coin(n,arr,size-1)+coin(n-arr[size-1],arr,size);
}
//DP
int coinDP(int n,int arr[],int size)
{
    int table[n+1][size+1];
    for(int i=0;i<n+1;i++)
    {
        table[i][0]=0;
    }
    for(int i=1;i<size+1;i++)
    {
        table[0][i]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<size+1;j++)
        {
            //without j
            int a=table[i][j-1];
            //with j
            int b=0;
            if(i-j>=0)
            {
                b=table[i-j][j];
            }
            table[i][j]=a+b;
        }
    }
    return table[n][size];
}
int main()
{
    int arr[10]={1,2,3};
    cout<<coin(4,arr,3)<<endl;
    cout<<coinDP(4,arr,3)<<endl;
    return 0;
}
