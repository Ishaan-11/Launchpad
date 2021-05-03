#include<iostream>
using namespace std;
void f(int x)
{
    cout<<"inside"<<endl;
    x++;
    cout<<x<<endl;
    cout<<"bye"<<endl;
    return;
}
void f1(int* x)
{
    cout<<"inside"<<endl;
    *x=*x+1;
    //*x++;//will increment in address then it will find the value
    cout<<*x<<endl;
    cout<<"bye"<<endl;
    return;
}
void f2(int** x)
{
    cout<<"inside"<<endl;
    *(*x)++;
    cout<<*x<<endl;//address of 104
    cout<<"bye"<<endl;
    return;
}
int* f3(int* x)
{
    *x++;
    return x;//will return address
}
int main()
{
    int x=10;
    cout<<x<<endl;
    //f(x);
    //f1(&x);
    int* ptr=&x;
    cout<<ptr<<endl;
    //f2(&ptr);
    int *ptr1=0;
    ptr1=f3(ptr);
    cout<<x<<endl;
    cout<<*ptr<<endl;
    cout<<ptr1<<endl;
    cout<<*ptr1<<endl;
    //cout<<ptr<<endl;//address of 104
    //cout<<*ptr<<endl;//value at 104
    //cout<<x<<endl;
    return 0;
}
