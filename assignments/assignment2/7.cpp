#include<iostream>
using namespace std;
int main()
{
    float basic,hra,da,pf,t_sal,allow;
    char grade;
    cout<<"enter the basic salary: ";
    cin>>basic;
    cout<<"enter the grade(A,B,C): ";
    cin>>grade;
    hra=basic*0.2;
    da=basic*0.5;
    pf=basic*0.11;
    if(grade=='A'||grade=='a')
    {
        allow=1700;
    }
    else if(grade=='B'||grade=='b')
    {
        allow=1500;
    }
    else if(grade=='C'||grade=='c')
    {
        allow=1300;
    }
    else
    {
        cout<<"invalid grade ";
        return 0;
    }
    t_sal=basic+hra+da+allow-pf;
    cout<<"total salary is: "<<t_sal;
    return 0;
}

