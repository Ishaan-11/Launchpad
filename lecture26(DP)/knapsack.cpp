#include<iostream>
using namespace std;
int knapsack(int p[],int w[],int n,int weight)
{
    int table[weight+1][n+1];
    for(int i=0;i<weight+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
                continue;
            }
            if(w[j-1]<=i)
            {
                table[i][j]=max(table[i][j-1],p[j-1]+table[i-w[j-1]][j-1]);
            }
            else
            {
                table[i][j]=table[i][j-1];
            }
        }
    }
    /*for(int i=0;i<weight+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return table[weight][n];
}
int main()
{
    int p[10]={1,2,5,6};
    int w[10]={2,3,4,5};
    int weight =8;
    cout<<knapsack(p,w,4,weight);
    return 0;
}
