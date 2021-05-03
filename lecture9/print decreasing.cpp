#include<iostream>
using namespace std;
void print_dec(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    print_dec(n-1);
    return;
}
int main()
{
    print_dec(5);
}
