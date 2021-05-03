#include<iostream>
using namespace std;
struct time
{
    int h,m,s;
};
void inputTime(time *t)
{
    cout<<"enter time "<<endl;
    cin>>(*t).h;
    cin>>(*t).m;
    cin>>(*t).s;
}
time dif(time t1,time t2)
{
    time t;
    if(t1.s<t2.s)
    {
        t1.m--;
        t1.s+=60;
    }
    t.s=t1.s-t2.s;
    if(t1.m<t2.m)
    {
        t1.h--;
        t1.m+=60;
    }
    t.m=t1.m-t2.m;
    t.h=t1.h-t2.h;
    return t;
}
void printTime(time t)
{
    cout<<t.h<<" : "<<t.m<<" : "<<t.s;
}
int main()
{
    time t1,t2;
    inputTime(&t1);
    inputTime(&t2);
    time t=dif(t1,t2);
    printTime(t);
    return 0;
}

