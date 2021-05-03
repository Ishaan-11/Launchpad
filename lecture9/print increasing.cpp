#include<iostream>
using namespace std;
void print_inc(int n)
{
    if(n==0)
    {
        return;
    }
    print_inc(n-1);
    cout<<n<<endl;
    return;
}
int main()
{
    print_inc(5);
}
