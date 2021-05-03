#include<iostream>
using namespace std;
int* f()
{
    int *ptr = new int;
    *ptr = 10;
    return ptr;
}
int* f1()
{
    int n;
    cin>>n;
    int * ptr = new int[n];
    for(int i=0;i<n;i++)
    {
        *(ptr+i)=i; //ptr[i] = i ;
    }
    return ptr;
}
void f2()//memory leak
{
    int n;
    cin>>n;
    int *ptr = new int[100];
    for(int i=0;i<n;i++)
    {
        *(ptr+i) = i;//ptr[i] = i ;
    }
    return;
}
int main()
{
    /*int x = 10;
    int * ptr = new int;
    *ptr = 14;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    delete ptr;
    cout<<*ptr<<endl;*/

    /*
    int * xptr = f();
    cout<<*xptr<<endl;
    delete xptr;
    cout<<*xptr<<endl;*/

    int* xptr=f1();
    cout<<*xptr<<endl;
    cout<<*(xptr+1)<<endl;
    delete []xptr;
}
