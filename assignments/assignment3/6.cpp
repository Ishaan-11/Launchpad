#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    float x1,x2,d,inc=0;
    cout<<" aX**2+b*X+c=0 "<<endl;
    cout<<"enter value of a: ";
    cin>>a;
    cout<<"enter value of b: ";
    cin>>b;
    cout<<"enter value of c: ";
    cin>>c;
    d=(b*b)-(4*a*c);
    if(d==0)
    {
        cout<<"roots are real and equal "<<endl;
    }
    else if(d>0)
    {
        cout<<"roots are real and distinct "<<endl;
        inc=1;
    }
    else
    {
        cout<<"no real roots ";
        return 0;
    }
    float sqrt_d=0;
    for(int i=0;i<3;i++)
    {
        while(sqrt_d*sqrt_d<d)
        {
            sqrt_d=sqrt_d+inc;
        }
        sqrt_d=sqrt_d-inc;
        inc=inc/10;
    }
    x1=((-b)+sqrt_d)/(2*a);
    x2=((-b)-sqrt_d)/(2*a);
    cout<<"roots are "<<x1<<" and "<<x2;
    return 0;
}
