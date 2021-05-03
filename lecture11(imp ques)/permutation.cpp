#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}
int permutation_with_count(char a[100],int index)
{
    int number=0;
    if(a[index]=='\0')
    {
        cout<<a<<endl;
        return 1;
    }
    for(int j=index;a[j]!='\0';j++)
    {
        swap(a[index],a[j]);
        number=number+permutation_with_count(a,index+1);
        swap(a[j],a[index]);
    }
    return number;
}
void permutation(char a[100],int index)
{
    if(a[index]=='\0')
    {
        cout<<a<<endl;
        return;
    }
    for(int j=index;a[j]!='\0';j++)
    {
        swap(a[index],a[j]);
        permutation(a,index+1);
        swap(a[j],a[index]);
    }
    return;
}
void permutation(int b[10],int n,int index)
{
    if(index==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<b[i];
        }
        cout<<endl;
        return;
    }
    for(int j=index;j<n;j++)
    {
        swap(b[index],b[j]);
        permutation(b,n,index+1);
        swap(b[j],b[index]);
    }
    return;
}
int main()
{
    char a[100];
    //int b[10];
    cout<<"enter a string"<<endl;
    cin.getline(a,100);
    /*cout<<"enter elements in array"<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    cout<<"permutations are"<<endl;
    permutation(b,3,0);*/
    permutation(a,0);
    //cout<<permutation_with_count(a,0);
    return 0;
}
