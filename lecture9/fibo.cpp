#include<iostream>
using namespace std;
int fibo(int n)
{
   if(n==1)
   {
       return 0;
   }
   if(n==2)
   {
       return 1;
   }
   int a=fibo(n-2);
   int b=fibo(n-1);
   return a+b;
}
int main()
{
    cout<<fibo(5);
}
