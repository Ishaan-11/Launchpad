#include<iostream>
using namespace std;
void print(int n)
{
    switch(n)
    {
        case 0:
            cout<<"zero ";
            break;
        case 1:
            cout<<"one ";
            break;
        case 2:
            cout<<"two ";
            break;
        case 3:
            cout<<"three ";
            break;
        case 4:
            cout<<"four ";
            break;
        case 5:
            cout<<"five ";
            break;
        case 6:
            cout<<"six ";
            break;
        case 7:
            cout<<"seven ";
            break;
        case 8:
            cout<<"eight ";
            break;
        case 9:
            cout<<"nine ";
            break;
        default:
            break;
    }
    return;
}
void f(int n)
{
    if(n/10==0)
    {
        print(n);
        return;
    }
    f(n/10);
    print(n%10);
    return;
}
int main()
{
    f(2048);
}
